#ifndef AEDSTAGE_H
#define AEDSTAGE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <QString>
#include <QObject>
#include <QThread>
#include <QDebug>
#include "constants.h"

using namespace std;

class AEDStage: public QObject {
    Q_OBJECT

    public:
        //constructor
        AEDStage();

        //destructor
        virtual ~AEDStage();

        //other
        virtual void start() = 0;
        StageOrderInSequence getOrderInSequence();

    protected:
        QString displayText;
        StageOrderInSequence orderInSequence;

    signals:
        void updateDisplay(QString);

};
#endif
