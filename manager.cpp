#include "manager.h"

Manager::Manager() {
    mNumber = 0;
}

Manager::~Manager() {
}

int Manager::addNumbers(int a, int b) {
    return a + b;
}

int Manager::getNumber() {
    return mNumber;
}
