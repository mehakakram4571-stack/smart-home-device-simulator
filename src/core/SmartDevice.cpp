#include <iostream>
#include "SmartDevice.h"

// Constructor using an Initializer List
SmartDevice::SmartDevice(int id, string n, string loc, float firmware)
    : deviceID(id), name(n), location(loc), isOn(false), firmwareVersion(firmware) {}

// Destructor definition
SmartDevice::~SmartDevice() {}

// Core logic method
void SmartDevice::toggle() {
    isOn = !isOn; 
}

// Normal virtual method implementation
void SmartDevice::restart() {
    cout << name << " is restarting firmware version " << firmwareVersion << "...\n";
}

// Getter and Setter Implementations
int SmartDevice::getDeviceID() const { return deviceID; }
string SmartDevice::getName() const { return name; }
string SmartDevice::getLocation() const { return location; }
bool SmartDevice::getIsOn() const { return isOn; }

void SmartDevice::setName(string n) { name = n; }
void SmartDevice::setLocation(string loc) { location = loc; }