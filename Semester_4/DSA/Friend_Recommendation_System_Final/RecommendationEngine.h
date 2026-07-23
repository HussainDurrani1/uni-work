#pragma once
#include "Graph.h"
#include "DynamicArray.h"
#include "HashMap.h"
#include <string>

using namespace std;

struct Recommendation {
    int userId;
    int mutualFriends;
    int sharedInterests;
    double interestSimilarity;
    int distance;
    double score;

    Recommendation()
        : userId(-1), mutualFriends(0), sharedInterests(0),
          interestSimilarity(0), distance(0), score(0) {}
};

struct UserProfile {
    int id;
    DynamicArray<string> interests;

    UserProfile() : id(-1) {}
    UserProfile(int id) : id(id) {}
};

class RecommendationEngine {
public:
    DynamicArray<Recommendation> generateRecommendations(
        int targetId,
        const Graph& graph,
        const HashMap<int, UserProfile>& profiles,
        int topK = 5
    ) const {
        DynamicArray<Recommendation> recommendations;
        DynamicArray<BFSEntry> candidates = graph.bfs(targetId, 3);

        HashMap<int, bool> excluded;
        excluded.insert(targetId, true);

        LinkedList<int> currentFriends = graph.getFriends(targetId);
        LinkedList<int>::Node* node = currentFriends.getHead();
        while (node) {
            excluded.insert(node->data, true);
            node = node->next;
        }

        for (int i = 0; i < candidates.size(); i++) {
            int candidateId = candidates[i].userId;
            int distance = candidates[i].distance;

            if (excluded.contains(candidateId) || !profiles.contains(candidateId)) continue;

            const UserProfile* target = profiles.get(targetId);
            const UserProfile* candidate = profiles.get(candidateId);
            if (!target || !candidate) continue;

            Recommendation item;
            item.userId = candidateId;
            item.distance = distance;
            item.mutualFriends = graph.countMutualFriends(targetId, candidateId);
            item.sharedInterests = countSharedInterests(*target, *candidate);
            item.interestSimilarity = calculateInterestSimilarity(*target, *candidate);
            item.score = calculateScore(targetId, candidateId, distance, graph, profiles);
            recommendations.pushBack(item);
        }

        rankRecommendations(recommendations);

        DynamicArray<Recommendation> top;
        int limit = topK < recommendations.size() ? topK : recommendations.size();
        for (int i = 0; i < limit; i++) top.pushBack(recommendations[i]);
        return top;
    }

    double calculateScore(
        int targetId,
        int candidateId,
        int distance,
        const Graph& graph,
        const HashMap<int, UserProfile>& profiles
    ) const {
        double score = graph.countMutualFriends(targetId, candidateId) * 10.0;

        const UserProfile* target = profiles.get(targetId);
        const UserProfile* candidate = profiles.get(candidateId);

        if (target && candidate) {
            score += countSharedInterests(*target, *candidate) * 7.0;
            score += calculateInterestSimilarity(*target, *candidate) * 20.0;
        }

        if (distance == 2) score += 15.0;
        else if (distance == 3) score += 8.0;

        return score;
    }

    int countSharedInterests(const UserProfile& first, const UserProfile& second) const {
        HashMap<string, bool> set;
        for (int i = 0; i < first.interests.size(); i++) set.insert(first.interests[i], true);

        int count = 0;
        for (int i = 0; i < second.interests.size(); i++) {
            if (set.contains(second.interests[i])) count++;
        }
        return count;
    }

    double calculateInterestSimilarity(const UserProfile& first, const UserProfile& second) const {
        int shared = countSharedInterests(first, second);
        int total = first.interests.size() + second.interests.size() - shared;
        if (total == 0) return 0;
        return (double)shared / total;
    }

    void rankRecommendations(DynamicArray<Recommendation>& recommendations) const {
        recommendations.sortDescending([](const Recommendation& first, const Recommendation& second) {
            return first.score > second.score;
        });
    }
};
