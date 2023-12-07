
#ifndef VICTIM_H
#define VICTIM_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/* Class Purpose:
*
* Data Members:
* - int heartRate: the heart rate of the victim
* - bool shockable: whether the victim can be shocked or not
* - bool isChild: whether the victim is a child or not
* - bool isLarge: whether the victim is large or not
* - bool hasPacemaker: whether the victim has the pacemaker on or not
* - bool isUpperPadOn: whether the victim has the upper pads on or not
* - bool isLowerPadOn: whether the victim has the lower pads on or not
*
* Class Functions:
* - void setIsChild(): set whether the victim is a child or not
* - void applyUpperPad(): apply the upper pad to the victim
* - void applyLowerPad(): apply the lower pad to the victim
* - void removeUpperPad(): remove the upper pad from the victim
* - void removeLowerPad(): remove the lower pad from the victim
* - int getHeartRate(): gets the heart rate of the victim, randomly generates a heart rate to provide to the program
* - bool getIsChild(): gets whether the victim is a child or not
* - bool getIsLarge(): gets whether the victim is large or not
* - bool getHasPacemaker(): gets whether the victim has the pacemaker or not
* - bool getIsUpperPadOn(): gets whether the victim has the upper pad on or not
* - bool getIsLowerPadOn(): gets whether the victim has the lower pad on or not
* - bool isShockable(): gets whether the victim is shockable or not
* - void setShockable(): set whether the victim can be shocked or not
*/


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
