#ifndef ELECTRODESTAGE_H
#define ELECTRODESTAGE_H

#include "aedStage.h"

class ElectrodeStage : public AEDStage {

    public:
        ElectrodeStage();
        ~ElectrodeStage();

        void start();
};
#endif
