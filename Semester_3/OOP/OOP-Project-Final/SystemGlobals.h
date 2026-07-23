#pragma once
#include "Rider.h"
#include "Driver.h"
#include "Admin.h"
#include "MatchingEngine.h"
#include "BookingManager.h"

const int MAX_DB_USERS = 50;

Rider* riders[MAX_DB_USERS];
int riderCount = 0;

Driver* drivers[MAX_DB_USERS];
int driverCount = 0;

Admin* systemAdmin = nullptr;
MatchingEngine* engine = nullptr;
BookingManager* bookingMgr = nullptr;

void setupSystem() {
    systemAdmin = new Admin(1, "System Admin", "admin", "admin@sys.com");
    engine = new MatchingEngine();
    bookingMgr = new BookingManager(engine);
}
