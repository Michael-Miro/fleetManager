// RideTicker.h
#ifndef RIDETICKET_H
#define RIDETICKET_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

enum WorkType {
    DELIVERY,
    PICKUP,
    MAINTENACE
};

class RideTicket {
public:
    RideTicket();
    RideTicket(std::string name, std::string currentLocation, std::string endLocation ,std::string plate, int startOdometer ,std::tm date , WorkType type);
    RideTicket(std::string driverName,std::string startLocation,std::string endLocation,std::string truckLicensePlate,int startOdometer,WorkType workTypeEnum);
    ~RideTicket();
    void setDate(int day, int month, int year);
    int RideDistance(int mStartOdometer, int mEndOdometer);
    int getStartOdometer() const;
    void setStartOdometer(int odometer);
    int getEndOdometer() const;
    void setEndOdometer(int odometer);
    void setTruckLicensePlate(std::string plate);
    std::string getTruckLicensePlate() const;
    void setStartLocation(std::string location);
    std::string getStartLocation() const;
    void setEndLocation(std::string location);
    std::string getEndLocation() const;
    void setDriverName(std::string name);
    std::string getDriverName() const;
    WorkType getWorkType() const;
    void setWorkType(WorkType type);
    void displayTicket();

private:
    int mStartOdometer;
    int mEndOdometer;
    std::string mTruckLicensePlate;
    std::string mStartLocation;
    std::string mEndLocation;
    std::string mDriverName;
    std::tm RideDate;
    WorkType mWorkType;
};


#endif
