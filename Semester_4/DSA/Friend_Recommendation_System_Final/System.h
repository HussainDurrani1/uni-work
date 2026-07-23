#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "User.h"
#include "Graph.h"
#include "RecommendationEngine.h"
#include "FileManager.h"
#include "helpers.h"

using namespace std;

class FriendRecommendationSystem {
private:
    unordered_map<int, User> users;
    Graph graph;
    RecommendationEngine engine;
    int nextId;

    HashMap<int, UserProfile> buildProfiles() const {
        HashMap<int, UserProfile> profiles;

        for (const auto& item : users) {
            const User& user = item.second;
            UserProfile profile(user.id);

            for (const string& interest : user.interests) {
                profile.interests.pushBack(interest);
            }

            profiles.insert(user.id, profile);
        }

        return profiles;
    }

    vector<string> splitInterests(const string& line) {
        vector<string> interests;
        string current;

        for (char character : line) {
            if (character == ',') {
                if (!current.empty()) interests.push_back(current);
                current.clear();
            } else {
                current += character;
            }
        }

        if (!current.empty()) interests.push_back(current);
        return interests;
    }

    void registerUser() {
        cout << "Enter name: ";
        string name;
        getline(cin, name);

        if (name.empty()) {
            cout << "Name cannot be blank.\n";
            return;
        }

        cout << "Enter interests separated by commas: ";
        string interestLine;
        getline(cin, interestLine);

        while (users.count(nextId)) nextId++;

        users[nextId] = User(nextId, name, splitInterests(interestLine));
        graph.addUser(nextId);
        cout << "User registered with ID: " << nextId << "\n";
        nextId++;
    }

    void addFriendMenu() {
        int first = getIntInput("Enter first user ID: ");
        if (!validateUserExists(first, users)) return;

        int second = getIntInput("Enter second user ID: ");
        if (!validateUserExists(second, users)) return;

        if (first == second) {
            cout << "Cannot friend yourself.\n";
            return;
        }

        if (graph.areFriends(first, second)) {
            cout << "Already friends.\n";
            return;
        }

        graph.addFriend(first, second);
        cout << users[first].name << " and " << users[second].name << " are now friends.\n";
    }

    void removeFriendMenu() {
        int first = getIntInput("Enter first user ID: ");
        if (!validateUserExists(first, users)) return;

        int second = getIntInput("Enter second user ID: ");
        if (!validateUserExists(second, users)) return;

        if (!graph.areFriends(first, second)) {
            cout << "These users are not friends.\n";
            return;
        }

        graph.removeFriend(first, second);
        cout << "Friendship removed.\n";
    }

    void viewFriends() {
        int id = getIntInput("Enter user ID: ");
        if (!validateUserExists(id, users)) return;

        LinkedList<int> friends = graph.getFriends(id);
        cout << "\nFriends of " << users[id].name << ":\n";
        printDivider('-', 35);

        if (friends.isEmpty()) {
            cout << "No friends yet.\n";
        } else {
            LinkedList<int>::Node* node = friends.getHead();
            while (node) {
                auto user = users.find(node->data);
                if (user != users.end()) cout << "[" << node->data << "] " << user->second.name << "\n";
                node = node->next;
            }
        }

        printDivider('-', 35);
    }

    void viewMutualFriends() {
        int first = getIntInput("Enter first user ID: ");
        if (!validateUserExists(first, users)) return;

        int second = getIntInput("Enter second user ID: ");
        if (!validateUserExists(second, users)) return;

        cout << "Mutual friends: " << graph.countMutualFriends(first, second) << "\n";
        LinkedList<int> firstFriends = graph.getFriends(first);
        LinkedList<int> secondFriends = graph.getFriends(second);

        LinkedList<int>::Node* firstNode = firstFriends.getHead();
        while (firstNode) {
            LinkedList<int>::Node* secondNode = secondFriends.getHead();
            while (secondNode) {
                if (firstNode->data == secondNode->data && users.count(firstNode->data)) {
                    cout << "[" << firstNode->data << "] " << users[firstNode->data].name << "\n";
                }
                secondNode = secondNode->next;
            }
            firstNode = firstNode->next;
        }
    }

    void displayRecommendations() {
        int id = getIntInput("Enter user ID: ");
        if (!validateUserExists(id, users)) return;

        int topK = getIntInput("How many recommendations: ");
        if (topK <= 0) topK = 5;

        HashMap<int, UserProfile> profiles = buildProfiles();
        DynamicArray<Recommendation> result = engine.generateRecommendations(id, graph, profiles, topK);
        vector<Recommendation> recommendations;

        for (int i = 0; i < result.size(); i++) recommendations.push_back(result[i]);

        cout << "\nTop recommendations for " << users[id].name << ":\n";
        printRecommendationTable(recommendations, users);
    }

    void searchUser() {
        cout << "Enter name to search: ";
        string query;
        getline(cin, query);
        query = toLowerString(query);

        bool found = false;
        for (const auto& item : users) {
            if (toLowerString(item.second.name).find(query) != string::npos) {
                cout << "[" << item.first << "] " << item.second.name << "\n";
                found = true;
            }
        }

        if (!found) cout << "No users found.\n";
    }

    void listAllUsers() {
        if (users.empty()) {
            cout << "No users registered.\n";
            return;
        }

        for (const auto& item : users) printUserCard(item.second);
    }

    void loadFromFiles() {
        FileManager manager;
        users = manager.loadUsers("users.txt");

        if (users.empty()) {
            cout << "No users were loaded.\n";
            return;
        }

        graph = Graph();
        nextId = 1;

        for (const auto& item : users) {
            graph.addUser(item.first);
            if (item.first >= nextId) nextId = item.first + 1;
        }

        vector<pair<int, int>> friendships = manager.loadFriendships("friends.txt");
        int loaded = 0;

        for (const auto& friendship : friendships) {
            if (users.count(friendship.first) && users.count(friendship.second)) {
                graph.addFriend(friendship.first, friendship.second);
                loaded++;
            }
        }

        cout << "Loaded " << users.size() << " users and " << loaded << " friendships.\n";
    }

    void saveToFiles() {
        FileManager manager;
        manager.saveUsers(users, "users.txt");

        const HashMap<int, LinkedList<int>>& source = graph.getAdjList();
        unordered_map<int, vector<int>> adjList;

        for (int i = 0; i < source.getBucketCount(); i++) {
            LinkedList<HashMap<int, LinkedList<int>>::KeyValue>::Node* item = source.getBuckets()[i].getHead();

            while (item) {
                int id = item->data.key;
                LinkedList<int>::Node* friendNode = item->data.value.getHead();

                while (friendNode) {
                    adjList[id].push_back(friendNode->data);
                    friendNode = friendNode->next;
                }

                item = item->next;
            }
        }

        manager.saveFriendships(adjList, "friends.txt");
        cout << "Data saved successfully.\n";
    }

public:
    FriendRecommendationSystem() : nextId(1) {}

    void showMenu() {
        cout << "\n";
        printDivider('=', 45);
        cout << "Friend Recommendation System\n";
        printDivider('=', 45);
        cout << "1. Load data from files\n";
        cout << "2. Register new user\n";
        cout << "3. Add friendship\n";
        cout << "4. Remove friendship\n";
        cout << "5. View all users\n";
        cout << "6. View user's friends\n";
        cout << "7. View mutual friends\n";
        cout << "8. Get friend recommendations\n";
        cout << "9. Search user by name\n";
        cout << "10. Save data to files\n";
        cout << "0. Exit\n";
        printDivider('=', 45);
    }

    void run() {
        cout << "Welcome to the Friend Recommendation System!\n";

        int choice = -1;
        while (choice != 0) {
            showMenu();
            choice = getIntInput("Enter choice: ");

            switch (choice) {
                case 1: loadFromFiles(); break;
                case 2: registerUser(); break;
                case 3: addFriendMenu(); break;
                case 4: removeFriendMenu(); break;
                case 5: listAllUsers(); break;
                case 6: viewFriends(); break;
                case 7: viewMutualFriends(); break;
                case 8: displayRecommendations(); break;
                case 9: searchUser(); break;
                case 10: saveToFiles(); break;
                case 0: cout << "Goodbye!\n"; break;
                default: cout << "Invalid choice.\n";
            }
        }
    }
};
