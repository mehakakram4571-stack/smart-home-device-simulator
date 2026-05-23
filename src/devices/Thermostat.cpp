#include <iostream>
#include "Thermostat.h"

Thermostat::Thermostat(int id, string n, string loc, float firmware)
    : SmartDevice(id, n, loc, firmware), targetTemperature(22.0), currentTemperature(20.0), mode("auto") {}

void Thermostat::setTemperature(double temp) {
    targetTemperature = temp;
    cout << getName() << " target temperature set to " << targetTemperature << "C\n";
}

void Thermostat::changeMode(string newMode) {
    if (newMode == "heat" || newMode == "cool" || newMode == "auto") {
        mode = newMode;
        cout << getName() << " mode changed to " << mode << "\n";
    } else {
        cout << "Invalid mode: " << newMode << ". Use heat, cool, or auto.\n";
    }
}

void Thermostat::schedule() {
    cout << getName() << " schedule activated. Maintaining " << targetTemperature << "C (" << mode << " mode)\n";
}

void Thermostat::cancelSchedule() {
    cout << getName() << " schedule cancelled. Running manually.\n";
}

string Thermostat::getStatus() {
    string state = getIsOn() ? "ON" : "OFF";
    return getName() + " [ID: " + to_string(getDeviceID()) + "] | State: " + state
           + " | Mode: " + mode
           + " | Current: " + to_string(currentTemperature) + "C"
           + " | Target: " + to_string(targetTemperature) + "C";
}

void Thermostat::generateReport() {
    cout << "\n=== Thermostat Report ===\n";
    cout << "Device: " << getName() << "\n";
    cout << "ID: " << getDeviceID() << "\n";
    cout << "Location: " << getLocation() << "\n";
    cout << "Status: " << (getIsOn() ? "On" : "Off") << "\n";
    cout << "Mode: " << mode << "\n";
    cout << "Current Temperature: " << currentTemperature << "C\n";
    cout << "Target Temperature: " << targetTemperature << "C\n";
    cout << "========================\n\n";
}
