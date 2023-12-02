#ifndef SHOCKSTAGE_H
#define SHOCKSTAGE_H

#include "aedStage.h"
#include "victim.h"

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
