#pragma once
#include "User.h"
#include "Graph.h"
#include "RecommendationEngine.h"
#include "FileManager.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cctype>

using namespace std;

void printDivider(char character, int width) {
    for (int i = 0; i < width; i++) cout << character;
    cout << "\n";
}

void printUserCard(const User& user) {
    user.display();
}

void printRecommendationTable(const vector<Recommendation>& recommendations,
                              const unordered_map<int, User>& users) {
    if (recommendations.empty()) {
        cout << "No recommendations found.\n";
        return;
    }

    printDivider('=', 70);
    cout << left
         << setw(6) << "Rank"
         << setw(24) << "User"
         << setw(10) << "Score"
         << setw(10) << "Mutuals"
         << setw(10) << "Shared"
         << setw(10) << "Distance" << "\n";
    printDivider('-', 70);

    for (int i = 0; i < (int)recommendations.size(); i++) {
        const Recommendation& item = recommendations[i];
        string userName = "Unknown";
        auto user = users.find(item.userId);
        if (user != users.end()) {
            userName = user->second.name + " (ID:" + to_string(item.userId) + ")";
        }

        cout << left
             << setw(6) << i + 1
             << setw(24) << userName
             << setw(10) << fixed << setprecision(1) << item.score
             << setw(10) << item.mutualFriends
             << setw(10) << item.sharedInterests
             << setw(10) << item.distance << "\n";
    }

    printDivider('=', 70);
}

bool validateUserExists(int id, const unordered_map<int, User>& users) {
    if (users.find(id) == users.end()) {
        cout << "User ID not found.\n";
        return false;
    }
    return true;
}

string toLowerString(string text) {
    transform(text.begin(), text.end(), text.begin(), [](unsigned char character) {
        return (char)tolower(character);
    });
    return text;
}

int getIntInput(const string& prompt) {
    int value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
    }
}

void autoTest() {
    int passed = 0;
    int failed = 0;

    auto showResult = [&](const string& name, bool success) {
        cout << left << setw(42) << name << (success ? "PASS" : "FAIL") << "\n";
        if (success) passed++;
        else failed++;
    };

    FileManager manager;
    unordered_map<int, User> users = manager.loadUsers("users.txt");
    showResult("Load users", !users.empty());

    Graph graph;
    for (const auto& item : users) graph.addUser(item.first);

    vector<pair<int, int>> friendships = manager.loadFriendships("friends.txt");
    for (const auto& friendship : friendships) graph.addFriend(friendship.first, friendship.second);
    showResult("Load friendships", !friendships.empty());

    DynamicArray<BFSEntry> bfsResult = graph.bfs(1, 2);
    showResult("BFS depth 2", bfsResult.size() > 0);
    showResult("Mutual friends", graph.countMutualFriends(1, 6) >= 0);

    HashMap<int, UserProfile> profiles;
    for (const auto& item : users) {
        UserProfile profile(item.first);
        for (const string& interest : item.second.interests) profile.interests.pushBack(interest);
        profiles.insert(item.first, profile);
    }

    RecommendationEngine engine;
    DynamicArray<Recommendation> recommendations = engine.generateRecommendations(1, graph, profiles, 5);
    showResult("Recommendation limit", recommendations.size() <= 5);
    showResult("Recommendation score", recommendations.size() == 0 || recommendations[0].score >= 0);

    cout << "Passed: " << passed << "  Failed: " << failed << "\n";
}
