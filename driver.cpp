#include "driver.h"
#include <fstream>
Driver::Driver() {
}

Driver::~Driver() {
}

std::string Driver::getDriverName() const{
    return mName;
}

void Driver::setDriverName(std::string name) {
    mName = name;
}
void Driver::setLicenseExpire(int day, int month, int year) {
    mLicenseExpire.tm_mday = day;
    mLicenseExpire.tm_mon = month;
    mLicenseExpire.tm_year = year;
}

bool Driver::isValidLicense()
{
    time_t currentTime = time(NULL);
    tm *localTime = localtime(&currentTime);
    cout <<"current date : " << localTime->tm_mday << "/" << localTime->tm_mon+1 << "/" << localTime->tm_year+1900 << endl;
    if(localTime->tm_year+1900 > mLicenseExpire.tm_year || 
    ((localTime->tm_year+1900 < mLicenseExpire.tm_year) && (localTime->tm_mon+1 > mLicenseExpire.tm_mon)) || 
    ((localTime->tm_year+1900 < mLicenseExpire.tm_year) && (localTime->tm_mon+1 < mLicenseExpire.tm_mon) && (localTime->tm_mday > mLicenseExpire.tm_mday)))
    {
        cout << "License expierd !"<<endl;
        return false;
    }
    return true;
}
void Driver::addNewTicket()
{
    time_t currentTime = time(NULL);
    tm *localTime = localtime(&currentTime);
    cout << "Please enter current location : " << endl;
    std::string curLocation;
    cin >> curLocation;
    cout << "Please enter end location : " << endl;
    std::string endLocation;
    cin >> endLocation;
    cout << "Please enter plate number : " << endl;
    std::string plate;
    cin >> plate;
    cout << "Please enter start odometer : " << endl;
    int odometer;
    cin >> odometer;
    cout << "Please work type : " << endl << "0 : DELIVERY" <<endl << "1 : PICKUP" <<endl<<"2 :MAINTENACE" <<endl;   
    int type;
    cin >> type;
    WorkType eType = (WorkType)type;
    RideTicket newTicket(Driver::getDriverName(),curLocation,endLocation,plate,odometer,*localTime,eType);
    mTickets.push_back(newTicket);
}
void Driver::closeOpendTicket()
{
    int endOdometer;
    cout << "Please enter end odometer" << endl;
    cin >> endOdometer;
    mTickets.back().setEndOdometer(endOdometer);
    cout << "Total ride distance : " << mTickets.back().RideDistance(mTickets.back().getStartOdometer(),mTickets.back().getEndOdometer()) << "KM" << endl;
}
RideTicket Driver::getLastTicket()
{
    return mTickets.back();
}
void Driver::WriteTicketsToFile() 
{

    std::ofstream outFile(getDriverName() + "Tickets.txt");
    // Write the vector to the file
    for (const auto &ticket : mTickets) 
    {
        outFile << ticket.getDriverName() << " " << ticket.getTruckLicensePlate() << " " <<  ticket.getStartOdometer() << " " 
                << ticket.getEndOdometer() << " " << ticket.getStartLocation() << " " << ticket.getEndLocation() << " " 
                << static_cast<int>(ticket.getWorkType()) << std::endl;
    }

    // Close the file
    outFile.close();

}

void Driver::ReadTicketsFromFile()
{
    // Clear the vector
    mTickets.clear();

    // Open a file for reading
    std::ifstream inFile(getDriverName() + "Tickets.txt");
    // Read data from the file
    std::string driverName;
    std::string truckLicensePlate;
    int startOdometer;
    int endOdometer;
    std::string startLocation;
    std::string endLocation;
    int workType;

    while(inFile >> driverName >> truckLicensePlate >> startOdometer >> endOdometer >> startLocation >> endLocation >> workType) {
        WorkType workTypeEnum;
        switch (workType) {
            case 0:
                workTypeEnum = WorkType::DELIVERY;
                break;
            case 1:
                workTypeEnum = WorkType::PICKUP;
                break;
            case 2:
                workTypeEnum = WorkType::MAINTENACE;
                break;
        }
        // Create a new RideTicket object and add it to the vector
        RideTicket newTicket(driverName, startLocation, endLocation, truckLicensePlate, startOdometer, workTypeEnum);
        mTickets.push_back(newTicket);
        // Close the file
        inFile.close();
        }

}
vector<RideTicket> Driver::getTicketsVec()
{
    return mTickets;
}