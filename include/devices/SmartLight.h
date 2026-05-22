#ifndef SMARTLIGHT_H
#define SMARTLIGHT_H

#include <string>
#include "SmartDevice.h"

using namespace std;

class SmartLight : public SmartDevice {
private:
    int brightness;
    int colorTemperature;
    string hexColor;

public:
    SmartLight(int id, string n, string loc, float firmware = 1.0f);

    void setBrightness(int level);
    void setColor(string hex);
    void dimToSunset();

    string getStatus() override;
    void generateReport() override;
};

#endif
