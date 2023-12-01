
#ifndef VICTIM_H
#define VICTIM_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Victim {

    public:
        //constructor
        Victim();

        //other
        void setIsChild();
        void receiveShock();
        void applyUpperPad();
        void applyLowerPad();
        void removeUpperPad();
        void removeLowerPad();
        bool isFlatlined();

        //getters
        int getHeartRate();
        bool getUnconcious();
        bool getIsChild();
        bool getIsLarge();
        bool getHasPacemaker();
        bool getIsUpperPadOn();
        bool getIsLowerPadOn();

    private:
        int heartRate;
        bool isChild;
        bool isLarge;
        bool hasPacemaker;
        bool isUnconcious;
        bool isUpperPadOn;
        bool isLowerPadOn;


};
#endif
