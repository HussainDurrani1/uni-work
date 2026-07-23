#pragma once
#include "User.h"
#include "Driver.h"
#include "Utils.h"
#include <iostream>
using namespace std;

const int MAX_USERS = 100;
const int MAX_DRIVERS = 50;

class Admin : public User
{
private:
    char* role;
    int accessLevel;
    bool systemOnline;
    bool maintenanceMode;
    int totalUsersManaged;
    int totalDriversManaged;
    int totalRidesMonitored;
    int actionsPerformed;
    int complaintsResolved;

    User* users[MAX_USERS];
    int userCount;

    Driver* drivers[MAX_DRIVERS];
    int driverCount;

public:

    Admin() : User()
    {
        role = copyString("System Admin");
        accessLevel = 5;
        systemOnline = true;
        maintenanceMode = false;
        totalUsersManaged = 0;
        totalDriversManaged = 0;
        totalRidesMonitored = 0;
        actionsPerformed = 0;
        complaintsResolved = 0;

        userCount = 0;
        driverCount = 0;
        for (int i = 0; i < MAX_USERS; i++) users[i] = nullptr;
        for (int i = 0; i < MAX_DRIVERS; i++) drivers[i] = nullptr;
    }

    Admin(int id, const char* n, const char* p, const char* e) : User(id, n, p, e)
    {
        role = copyString("System Admin");
        accessLevel = 5;
        systemOnline = true;
        maintenanceMode = false;
        totalUsersManaged = 0;
        totalDriversManaged = 0;
        totalRidesMonitored = 0;
        actionsPerformed = 0;
        complaintsResolved = 0;

        userCount = 0;
        driverCount = 0;
        for (int i = 0; i < MAX_USERS; i++) users[i] = nullptr;
        for (int i = 0; i < MAX_DRIVERS; i++) drivers[i] = nullptr;
    }

    Admin(const Admin& other) : User(other)
    {
        role = copyString(other.role);
        accessLevel = other.accessLevel;
        systemOnline = other.systemOnline;
        maintenanceMode = other.maintenanceMode;
        totalUsersManaged = other.totalUsersManaged;
        totalDriversManaged = other.totalDriversManaged;
        totalRidesMonitored = other.totalRidesMonitored;
        actionsPerformed = other.actionsPerformed;
        complaintsResolved = other.complaintsResolved;

        userCount = other.userCount;
        driverCount = other.driverCount;
        for (int i = 0; i < userCount; i++) users[i] = other.users[i];
        for (int i = 0; i < driverCount; i++) drivers[i] = other.drivers[i];
    }

    Admin& operator=(const Admin& other)
    {
        if (this != &other)
        {
            User::operator=(other);

            delete[] role;
            role = copyString(other.role);

            accessLevel = other.accessLevel;
            systemOnline = other.systemOnline;
            maintenanceMode = other.maintenanceMode;
            totalUsersManaged = other.totalUsersManaged;
            totalDriversManaged = other.totalDriversManaged;
            totalRidesMonitored = other.totalRidesMonitored;
            actionsPerformed = other.actionsPerformed;
            complaintsResolved = other.complaintsResolved;

            userCount = other.userCount;
            driverCount = other.driverCount;
            for (int i = 0; i < userCount; i++) users[i] = other.users[i];
            for (int i = 0; i < driverCount; i++) drivers[i] = other.drivers[i];
        }
        return *this;
    }

    virtual ~Admin()
    {
        delete[] role;
    }

    void addUser(User* u)
    {
        if (userCount < MAX_USERS)
            users[userCount++] = u;
    }

    void addDriver(Driver* d)
    {
        if (driverCount < MAX_DRIVERS)
            drivers[driverCount++] = d;
    }

    const char* getRole() const { return role; }

    void setRole(const char* r)
    {
        delete[] role;
        role = copyString(r);
        actionsPerformed++;
    }

    void enableMaintenance() { maintenanceMode = true; systemOnline = false; actionsPerformed++; }

    void disableMaintenance() { maintenanceMode = false; systemOnline = true; actionsPerformed++; }

    bool isSystemOnline() const { return systemOnline; }

    void manageUser() { totalUsersManaged++; actionsPerformed++; }

    void manageDriver() { totalDriversManaged++; actionsPerformed++; }

    void monitorRide() { totalRidesMonitored++; }

    void resolveComplaint() { complaintsResolved++; actionsPerformed++; }

    void verifyDriver(int driverId)
    {
        for (int i = 0; i < driverCount; i++)
        {
            if (drivers[i] && drivers[i]->getUserId() == driverId)
            {
                drivers[i]->verifyDriver();
                cout << "Driver " << driverId << " verified.\n";
                actionsPerformed++;
                return;
            }
        }
        cout << "Driver " << driverId << " not found.\n";
    }

    void suspendDriver(int driverId)
    {
        for (int i = 0; i < driverCount; i++)
        {
            if (drivers[i] && drivers[i]->getUserId() == driverId)
            {
                drivers[i]->setActive(false);
                cout << "Driver " << driverId << " suspended.\n";
                actionsPerformed++;
                return;
            }
        }
        cout << "Driver " << driverId << " not found.\n";
    }

    void blockUser(int userId)
    {
        for (int i = 0; i < userCount; i++)
        {
            if (users[i] && users[i]->getUserId() == userId)
            {
                users[i]->setActive(false);
                cout << "User " << userId << " blocked.\n";
                actionsPerformed++;
                return;
            }
        }
        cout << "User " << userId << " not found.\n";
    }

    void unblockUser(int userId)
    {
        for (int i = 0; i < userCount; i++)
        {
            if (users[i] && users[i]->getUserId() == userId)
            {
                users[i]->setActive(true);
                cout << "User " << userId << " unblocked.\n";
                actionsPerformed++;
                return;
            }
        }
        cout << "User " << userId << " not found.\n";
    }

    virtual void display() const
    {
        User::display();
        cout << "Admin Info:\n";
        cout << "Role: " << role << endl;
        cout << "Access Level: " << accessLevel << endl;
        cout << "System Online: " << (systemOnline ? "Yes" : "No") << endl;
        cout << "Maintenance Mode: " << (maintenanceMode ? "Yes" : "No") << endl;
        cout << "Users Managed: " << totalUsersManaged << endl;
        cout << "Drivers Managed: " << totalDriversManaged << endl;
        cout << "Rides Monitored: " << totalRidesMonitored << endl;
        cout << "Actions Performed: " << actionsPerformed << endl;
        cout << "Complaints Resolved: " << complaintsResolved << endl;
    }

    virtual void updateProfile(const char* n, const char* p, const char* e)
    {
        User::updateProfile(n, p, e);
    }
};
