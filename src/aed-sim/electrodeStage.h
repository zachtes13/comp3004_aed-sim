#ifndef ELECTRODESTAGE_H
#define ELECTRODESTAGE_H

#include "aedStage.h"

class ElectrodeStage : public AEDStage {

    public:
        ElectrodeStage();
        ~ElectrodeStage();
        void start();

        void applyCprPads();
        void applyPediPads(Victim*);
        void applyUpperPad(Victim*);
        void applyLowerPad(Victim*);

};
#endif
