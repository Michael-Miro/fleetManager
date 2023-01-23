#include "RideTicket.h"

RideTicket::RideTicket() {
    mStartOdometer = 0;
    mEndOdometer = 0;
    mTruckLicensePlate = "" ; 
    mStartLocation = "" ; 
    mEndLocation = "" ; 
    mDriverName = "" ; 
    std::tm RideDate;
    WorkType mWorkType;
}
RideTicket::~RideTicket() {
}
RideTicket::RideTicket(std::string name, std::string currentLocation, std::string endLocation ,std::string plate, int startOdometer ,std::tm date , WorkType type)
{
    setDriverName(name);
    setStartLocation(currentLocation);
    setEndLocation(endLocation);
    setTruckLicensePlate(plate);
    setStartOdometer(startOdometer);
    setDate(date.tm_mday,date.tm_mon,date.tm_year);
    setWorkType(type);
}
RideTicket::RideTicket(std::string driverName,std::string startLocation,std::string endLocation,std::string truckLicensePlate,int startOdometer,WorkType workTypeEnum)
{
    setDriverName(driverName);
    setStartLocation(startLocation);
    setEndLocation(endLocation);
    setTruckLicensePlate(truckLicensePlate);
    setStartOdometer(startOdometer);
    setWorkType(workTypeEnum);
}
void RideTicket::setDate(int day, int month, int year) {
    RideDate.tm_mday = day;
    RideDate.tm_mon = month;
    RideDate.tm_year = year;
    }

int RideTicket::RideDistance(int mStartOdometer, int mEndOdometer) {
    return mEndOdometer - mStartOdometer;
}
int RideTicket::getStartOdometer() const{
    return mStartOdometer;
}
void RideTicket::setStartOdometer(int odometer) {
    mStartOdometer = odometer;
}
int RideTicket::getEndOdometer() const{
    return mEndOdometer;
}
void RideTicket::setEndOdometer(int odometer) {
    mEndOdometer = odometer;
}
void RideTicket::setTruckLicensePlate(std::string plate) {
    mTruckLicensePlate = plate;
}
std::string RideTicket::getTruckLicensePlate() const{
    return mTruckLicensePlate;
}
void RideTicket::setStartLocation(std::string location) {
    mStartLocation = location;
}
std::string RideTicket::getStartLocation() const{
    return mStartLocation;
}
void RideTicket::setEndLocation(std::string location) {
    mEndLocation = location;
}
std::string RideTicket::getEndLocation() const{
    return mEndLocation;
}
void RideTicket::setDriverName(std::string name) {
    mDriverName = name;
}
std::string RideTicket::getDriverName() const{
    return mDriverName;
}
WorkType RideTicket::getWorkType() const{
    return mWorkType;
}
void RideTicket::setWorkType(WorkType type) {
    mWorkType = type;
    }
void RideTicket::displayTicket() {
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "|                 Ride Ticket                 |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "| Date       : " << std::setw(14) << RideDate.tm_mday << "/" << RideDate.tm_mon << "/" << RideDate.tm_year << " |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "| Driver Name: " << std::setw(14) << mDriverName << " |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "| Work Type  : " << std::setw(14) << mWorkType << " |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "| Plate      : " << std::setw(14) << mTruckLicensePlate << " |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "| Start Loc  : " << std::setw(14) << mStartLocation << " |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "| End Loc    : " << std::setw(14) << mEndLocation << " |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "| S.Odometer : " << std::setw(14) << mStartOdometer << " |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "| E.Odometer : " << std::setw(14) << mEndOdometer << " |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "| Distance   : " << std::setw(14) << RideDistance(mStartOdometer, mEndOdometer) << " |" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
}

