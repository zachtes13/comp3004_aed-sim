#ifndef ANALYSISSTAGE_H
#define ANALYSISSTAGE_H

#include "aedStage.h"

class AnalysisStage : public AEDStage {

    public:
        AnalysisStage();
        ~AnalysisStage();

        void start();
};
#endif
