#pragma once
#include "HashMap.h"
#include "LinkedList.h"
#include "Queue.h"
#include "DynamicArray.h"

using namespace std;

struct BFSEntry {
    int userId;
    int distance;

    BFSEntry() : userId(-1), distance(0) {}
    BFSEntry(int userId, int distance) : userId(userId), distance(distance) {}
};

struct NodeDepth {
    int nodeId;
    int depth;

    NodeDepth() : nodeId(0), depth(0) {}
    NodeDepth(int nodeId, int depth) : nodeId(nodeId), depth(depth) {}
};

class Graph {
private:
    HashMap<int, LinkedList<int>> adjList;

public:
    void addUser(int id) {
        if (!adjList.contains(id)) adjList.insert(id, LinkedList<int>());
    }

    void addFriend(int u, int v) {
        addUser(u);
        addUser(v);

        LinkedList<int>* first = adjList.get(u);
        LinkedList<int>* second = adjList.get(v);

        if (!first->contains(v)) first->pushBack(v);
        if (!second->contains(u)) second->pushBack(u);
    }

    void removeFriend(int u, int v) {
        LinkedList<int>* first = adjList.get(u);
        LinkedList<int>* second = adjList.get(v);

        if (first) first->remove(v);
        if (second) second->remove(u);
    }

    bool areFriends(int u, int v) const {
        const LinkedList<int>* list = adjList.get(u);
        return list && list->contains(v);
    }

    LinkedList<int> getFriends(int id) const {
        const LinkedList<int>* list = adjList.get(id);
        if (!list) return LinkedList<int>();
        return *list;
    }

    DynamicArray<BFSEntry> bfs(int startId, int maxDepth) const {
        DynamicArray<BFSEntry> result;
        if (!adjList.contains(startId)) return result;

        HashMap<int, bool> visited;
        Queue<NodeDepth> pending;

        visited.insert(startId, true);
        pending.enqueue(NodeDepth(startId, 0));

        while (!pending.isEmpty()) {
            NodeDepth current = pending.front();
            pending.dequeue();

            if (current.depth >= maxDepth) continue;

            const LinkedList<int>* neighbours = adjList.get(current.nodeId);
            if (!neighbours) continue;

            LinkedList<int>::Node* node = neighbours->getHead();
            while (node) {
                if (!visited.contains(node->data)) {
                    int distance = current.depth + 1;
                    visited.insert(node->data, true);
                    result.pushBack(BFSEntry(node->data, distance));
                    pending.enqueue(NodeDepth(node->data, distance));
                }
                node = node->next;
            }
        }

        return result;
    }

    int countMutualFriends(int u, int v) const {
        const LinkedList<int>* first = adjList.get(u);
        const LinkedList<int>* second = adjList.get(v);
        if (!first || !second) return 0;

        HashMap<int, bool> firstSet;
        LinkedList<int>::Node* node = first->getHead();
        while (node) {
            firstSet.insert(node->data, true);
            node = node->next;
        }

        int count = 0;
        node = second->getHead();
        while (node) {
            if (firstSet.contains(node->data)) count++;
            node = node->next;
        }

        return count;
    }

    const HashMap<int, LinkedList<int>>& getAdjList() const {
        return adjList;
    }

    int userCount() const {
        return adjList.size();
    }
};
