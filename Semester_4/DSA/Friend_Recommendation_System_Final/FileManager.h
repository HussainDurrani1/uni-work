#pragma once
#include "User.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class FileManager {
private:
    vector<string> parseInterests(const string& line) {
        vector<string> interests;
        stringstream stream(line);
        string interest;

        while (getline(stream, interest, ',')) {
            while (!interest.empty() && interest.front() == ' ') interest.erase(interest.begin());
            while (!interest.empty() && interest.back() == ' ') interest.pop_back();
            if (!interest.empty()) interests.push_back(interest);
        }

        return interests;
    }

public:
    unordered_map<int, User> loadUsers(const string& filename) {
        unordered_map<int, User> users;
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Could not open " << filename << "\n";
            return users;
        }

        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;

            stringstream stream(line);
            string idText;
            string name;
            string interestText;

            getline(stream, idText, ',');
            getline(stream, name, ',');
            getline(stream, interestText);

            try {
                int id = stoi(idText);
                users[id] = User(id, name, parseInterests(interestText));
            } catch (...) {
                cerr << "Invalid user record: " << line << "\n";
            }
        }

        return users;
    }

    vector<pair<int, int>> loadFriendships(const string& filename) {
        vector<pair<int, int>> friendships;
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Could not open " << filename << "\n";
            return friendships;
        }

        int first;
        int second;
        while (file >> first >> second) friendships.push_back({first, second});
        return friendships;
    }

    void saveUsers(const unordered_map<int, User>& users, const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Could not write to " << filename << "\n";
            return;
        }

        vector<int> ids;
        for (const auto& item : users) ids.push_back(item.first);
        sort(ids.begin(), ids.end());

        for (int id : ids) {
            const User& user = users.at(id);
            file << user.id << "," << user.name;
            for (const string& interest : user.interests) file << "," << interest;
            file << "\n";
        }
    }

    void saveFriendships(const unordered_map<int, vector<int>>& adjList, const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Could not write to " << filename << "\n";
            return;
        }

        set<pair<int, int>> friendships;
        for (const auto& item : adjList) {
            for (int friendId : item.second) {
                int first = min(item.first, friendId);
                int second = max(item.first, friendId);
                friendships.insert({first, second});
            }
        }

        for (const auto& friendship : friendships) {
            file << friendship.first << " " << friendship.second << "\n";
        }
    }
};
