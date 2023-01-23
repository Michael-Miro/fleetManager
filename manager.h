// manager.h
#ifndef MANAGER_H
#define MANAGER_H

#include <driver.h>
#include <RideTicket.h>

class Manager {
public:
    Manager();
    ~Manager();
    
    int addNumbers(int a, int b);
    int getNumber();

private:
    int mNumber;
};

#endif
