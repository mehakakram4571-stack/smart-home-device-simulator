#include <iostream>
#include <algorithm>
#include "SmartLight.h"

SmartLight::SmartLight(int id, string n, string loc, float firmware)
    : SmartDevice(id, n, loc, firmware), brightness(100), colorTemperature(4000), hexColor("#FFFFFF") {}

void SmartLight::setBrightness(int level) {
    brightness = max(0, min(100, level));
    cout << getName() << " brightness set to " << brightness << "%\n";
}

void SmartLight::setColor(string hex) {
    hexColor = hex;
    cout << getName() << " color changed to " << hexColor << "\n";
}

void SmartLight::dimToSunset() {
    cout << getName() << " dimming to sunset mode...\n";
    brightness = 30;
    colorTemperature = 2200;
    hexColor = "#FFA07A";
    cout << getName() << " now in warm sunset mode (" << brightness << "% brightness, " << colorTemperature << "K)\n";
}

string SmartLight::getStatus() {
    string state = getIsOn() ? "ON" : "OFF";
    return getName() + " [ID: " + to_string(getDeviceID()) + "] | State: " + state
           + " | Brightness: " + to_string(brightness) + "%"
           + " | Temp: " + to_string(colorTemperature) + "K"
           + " | Color: " + hexColor;
}

void SmartLight::generateReport() {
    cout << "\n=== SmartLight Report ===\n";
    cout << "Device: " << getName() << "\n";
    cout << "ID: " << getDeviceID() << "\n";
    cout << "Location: " << getLocation() << "\n";
    cout << "Status: " << (getIsOn() ? "On" : "Off") << "\n";
    cout << "Brightness: " << brightness << "%\n";
    cout << "Color Temperature: " << colorTemperature << "K\n";
    cout << "Hex Color: " << hexColor << "\n";
    cout << "========================\n\n";
}
