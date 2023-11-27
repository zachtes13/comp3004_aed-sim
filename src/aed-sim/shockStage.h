#ifndef SHOCKSTAGE_H
#define SHOCKSTAGE_H

#include "aedStage.h"

class ShockStage : public AEDStage {

    public:
        ShockStage();
        ~ShockStage();

        void start();
};
#endif
