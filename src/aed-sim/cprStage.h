#ifndef CPRSTAGE_H
#define CPRSTAGE_H

#include "aedStage.h"

class CprStage : public AEDStage {
    public:
        CprStage();
        ~CprStage();
        void start();

        void startCompression();
        void stopCompression();

        QTimer* getStartTimer();
        QTimer* getStopTimer();

    private:
        QTimer* startTimer;
        QTimer* stopTimer;
};
#endif
