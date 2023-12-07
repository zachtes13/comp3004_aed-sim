#ifndef SHOCKSTAGE_H
#define SHOCKSTAGE_H

#include "aedStage.h"
#include "victim.h"

/* Class Purpose: The shocking stage for the AED
*
* Data Members:
* - Victim *victim: a pointer to the victim
*
* Class Functions:
* - void start(): The sequential walkthrough of the shocking stage of the AED
* - void countdown(): A count that plays (displays on UI) before a shock is delivered
* - void incrementShockCount(): a signal to the UI to increment the shock count
* - void drainBattery(): a signal to the UI to drain our battery
*/

class ShockStage : public AEDStage {
    Q_OBJECT

    public:
        ShockStage(Victim*);
        ~ShockStage();
        void start();

    private:
        Victim *victim;
        void countdown();

    signals:
        void incrementShockCount();
        void drainBattery();
};
#endif
