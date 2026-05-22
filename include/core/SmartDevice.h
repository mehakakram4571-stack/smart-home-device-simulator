#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>

using namespace std;

class SmartDevice {
private:
    int deviceID;
    string name;
    string location;
    bool isOn;
    float firmwareVersion;

public:
    // Constructor (Default arguments go in the header)
    SmartDevice(int id, string n, string loc, float firmware = 1.0f);

    // Virtual Destructor
    virtual ~SmartDevice();

    // Public Methods
    void toggle();
    virtual void restart();

    // Getters and Setters (Encapsulation)
    int getDeviceID() const;
    string getName() const;
    string getLocation() const;
    bool getIsOn() const;
    
    void setName(string n);
    void setLocation(string loc);

    // Pure Virtual Functions (Makes this an Abstract Base Class)
    virtual string getStatus() = 0; 
    virtual void generateReport() = 0;
};

#endif
