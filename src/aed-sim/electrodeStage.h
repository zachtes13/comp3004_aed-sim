#ifndef ELECTRODESTAGE_H
#define ELECTRODESTAGE_H

#include "aedStage.h"

class ElectrodeStage : public AEDStage {
    Q_OBJECT

    public:
        ElectrodeStage();
        ~ElectrodeStage();
        void start();

        void applyCprPads();
        void applyPediPads(Victim*);
        void applyUpperPad(Victim*);
        void applyLowerPad(Victim*);

    signals:
        void connectPads();
};
#endif
