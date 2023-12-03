
#ifndef VICTIM_H
#define VICTIM_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Victim {
    public:
        Victim();
        void setIsChild();
        void applyUpperPad();
        void applyLowerPad();
        void removeUpperPad();
        void removeLowerPad();
        int getHeartRate();
        bool getIsChild();
        bool getIsLarge();
        bool getHasPacemaker();
        bool getIsUpperPadOn();
        bool getIsLowerPadOn();
        bool isShockable();
        void setShockable(bool);

    private:
        int heartRate;
        bool shockable;
        bool isChild;
        bool isLarge;
        bool hasPacemaker;
        bool isUpperPadOn;
        bool isLowerPadOn;
};
#endif
