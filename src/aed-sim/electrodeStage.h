#ifndef ELECTRODESTAGE_H
#define ELECTRODESTAGE_H

#include "aedStage.h"

/* Class Purpose: The electrode stage for the AED
*
* Class Functions:
* - void start(): The sequential walkthrough of the electrode stage of the AED
* - void applyCprPads(): Apply cpr pads to the victim, the victim is an adult
* - void applyPediPads(): Apply pediatric pads to the victim, the victim is not an adult
* - void applyUpperPad(): Apply the upper pad to the victim
* - void applyLowerPad(): Apply the lower pad to the victim
* - void connectPads(): A signal to the UI to connect the pads to the victim
*/

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
