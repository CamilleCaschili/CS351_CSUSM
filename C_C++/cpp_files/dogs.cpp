#include <iostream>

#include "dogs.hpp"

using namespace std;

Dogs::Dogs(std::string name) {
    setName(name);

    cout << getName() << " bark for the first time" << endl;
}

Dogs::~Dogs() {
    cout << getName() << " is now in heaven because he was a very good boy!" << endl;
}

void Dogs::setName(std::string name) {
    _name = name;
}

std::string Dogs::getName() {
    return _name;
}