
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
        void receiveShock();
        void applyPads();
        void removePads();
        bool isFlatlined();

        //getters
        int getHeartRate();
        bool getUnconcious();
        bool getIsChild();
        bool getPadsOn();

    private:
        int heartRate;
        bool isUnconcious;
        bool isChild;
        bool padsOn;

};
#endif
