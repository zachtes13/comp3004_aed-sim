
#ifndef VICTIM_H
#define VICTIM_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Victim {

    public:
        Victim();
        void receiveShock();
        void applyPads();
        void removePads();
        bool isFlatlined();
        int getHeartRate();
        bool getUnconcious();
        bool getIsChild();
        bool getPadsOn();
        bool isShockable();
        void setShockable(bool);

    private:
        int heartRate;
        bool shockable;
        bool isUnconcious;
        bool isChild;
        bool padsOn;

};
#endif
