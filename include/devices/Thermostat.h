#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <string>
#include "SmartDevice.h"
#include "Schedulable.h"

using namespace std;

class Thermostat : public SmartDevice, public Schedulable {
private:
    double targetTemperature;
    double currentTemperature;
    string mode;

public:
    Thermostat(int id, string n, string loc, float firmware = 1.0f);

    void setTemperature(double temp);
    void changeMode(string newMode);

    void schedule() override;
    void cancelSchedule() override;

    string getStatus() override;
    void generateReport() override;
};

#endif
