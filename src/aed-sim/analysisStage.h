#ifndef ANALYSISSTAGE_H
#define ANALYSISSTAGE_H

#include "aedStage.h"
#include "victim.h"

class AnalysisStage : public AEDStage {
    Q_OBJECT

    public:
        AnalysisStage(Victim*);
        ~AnalysisStage();
        void start();

    private:
        Victim *victim;
        HEART_RATE diagnoseHeartRate(int);

    signals:
        void updateECGDisplay(HEART_RATE);
};
#endif
