#pragma once

#include <iostream>
#include "Utils.h"
#include "Notification.h"
using namespace std;

class User
{
protected:
    int userId;
    char* name;
    char* phone;
    char* email;
    float rating;
    int totalRatings;
    bool active;

    Notification** notifications;
    int notificationCount;
    int notificationCapacity;

public:
   
    User()
    {
        userId = 0;
        name = copyString("Unknown");
        phone = copyString("N/A");
        email = copyString("N/A");
        rating = 0.0f;
        totalRatings = 0;
        active = true;
        notifications = nullptr;
        notificationCount = 0;
        notificationCapacity = 0;
    }

    
    User(int id, const char* n, const char* p, const char* e)
    {
        userId = id;
        name = copyString(n);
        phone = copyString(p);
        email = copyString(e);
        rating = 0.0f;
        totalRatings = 0;
        active = true;
        notifications = nullptr;
        notificationCount = 0;
        notificationCapacity = 0;
    }

    User(const User& other)
    {
        userId = other.userId;
        name = copyString(other.name);
        phone = copyString(other.phone);
        email = copyString(other.email);
        rating = other.rating;
        totalRatings = other.totalRatings;
        active = other.active;

        notificationCount = other.notificationCount;
        notificationCapacity = other.notificationCapacity;
        if (other.notificationCapacity > 0) {
            notifications = new Notification * [notificationCapacity];
            for (int i = 0; i < notificationCount; i++) {
                notifications[i] = new Notification(*other.notifications[i]);
            }
        }
        else {
            notifications = nullptr;
        }
    }

    User& operator=(const User& other)
    {
        if (this != &other)
        {
            if (notifications != nullptr) {
                for (int i = 0; i < notificationCount; i++) delete notifications[i];
                delete[] notifications;
            }

            userId = other.userId;

            delete[] name;
            name = copyString(other.name);

            delete[] phone;
            phone = copyString(other.phone);

            delete[] email;
            email = copyString(other.email);

            rating = other.rating;
            totalRatings = other.totalRatings;
            active = other.active;

            notificationCount = other.notificationCount;
            notificationCapacity = other.notificationCapacity;
            if (other.notificationCapacity > 0) {
                notifications = new Notification * [notificationCapacity];
                for (int i = 0; i < notificationCount; i++) {
                    notifications[i] = new Notification(*other.notifications[i]);
                }
            }
            else {
                notifications = nullptr;
            }
        }
        return *this;
    }

    virtual ~User()
    {
        delete[] name;
        delete[] phone;
        delete[] email;

        if (notifications != nullptr) {
            for (int i = 0; i < notificationCount; i++) delete notifications[i];
            delete[] notifications;
        }
    }

    virtual void updateName(const char* n)
    {
        delete[] name;
        name = copyString(n);
    }

    virtual void updatePhone(const char* p)
    {
        delete[] phone;
        phone = copyString(p);
    }

    virtual void updateEmail(const char* e)
    {
        delete[] email;
        email = copyString(e);
    }

    virtual void updateProfile(const char* n, const char* p, const char* e)
    {
        updateName(n);
        updatePhone(p);
        updateEmail(e);
    }

    virtual void addRating(float newRating)
    {
        rating = (rating * totalRatings + newRating) / (totalRatings + 1);
        totalRatings++;
    }

    void setActive(bool status)
    {
        active = status;
    }

    bool isActive() const
    {
        return active;
    }

    int getUserId() const
    {
        return userId;
    }

    const char* getName() const
    {
        return name;
    }

    const char* getPhone() const
    {
        return phone;
    }

    const char* getEmail() const
    {
        return email;
    }

    float getRating() const
    {
        return rating;
    }

    virtual void display() const
    {
        cout << "User ID: " << userId << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        cout << "Rating: " << rating << " (" << totalRatings << " reviews)" << endl;
        cout << "Status: " << (active ? "Active" : "Inactive") << endl;
    }

    void addNotification(Notification* n) {
        if (notificationCount == notificationCapacity) {
            int newCapacity = (notificationCapacity == 0) ? 5 : notificationCapacity * 2;
            Notification** newNotes = new Notification * [newCapacity];
            for (int i = 0; i < notificationCount; i++) newNotes[i] = notifications[i];

            delete[] notifications;
            notifications = newNotes;
            notificationCapacity = newCapacity;
        }
        notifications[notificationCount++] = n;
    }

    void showNotifications() {
        cout << "--- Notifications ---" << endl;
        if (notificationCount == 0) cout << "No new notifications." << endl;
        else {
            for (int i = 0; i < notificationCount; i++) {
                notifications[i]->display();
                notifications[i]->markAsRead();
            }
        }
    }
};
