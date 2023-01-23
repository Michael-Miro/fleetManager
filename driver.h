// driver.h
#ifndef DRIVER_H
#define DRIVER_H

#include "RideTicket.h"
#include <vector>
#include <chrono>
#include <ctime> 
using namespace std;
class Driver {
public:
    Driver();
    ~Driver();

    void setDriverName(std::string name);
    std::string getDriverName() const;
    void setLicenseExpire(int day, int month, int year);
    bool isValidLicense();
    void addNewTicket();
    void closeOpendTicket();
    RideTicket getLastTicket();
    void WriteTicketsToFile();
    void ReadTicketsFromFile();
    vector<RideTicket> getTicketsVec();

private:
    std::string mName ;
    std::size_t mPersonalNumber;
    vector<RideTicket> mTickets;
    bool mValidLicense;
    std::tm mLicenseExpire;
};

#endif
