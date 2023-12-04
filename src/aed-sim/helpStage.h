#ifndef HELPSTAGE_H
#define HELPSTAGE_H

#include "aedStage.h"

class HelpStage : public AEDStage {

    public:
        HelpStage();
        ~HelpStage();
        void start();
        void getHelp();

    private:
        QTimer* stageTimer;
};
#endif
