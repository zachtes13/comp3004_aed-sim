#ifndef AEDSTAGE_H
#define AEDSTAGE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <QString>
#include <QObject>
#include <QThread>
#include <QTimer>
#include <QDebug>
#include "constants.h"
#include "victim.h"

using namespace std;

/* Class Purpose: The parent class of all AED stages, contains function definitions and variables that all AED stages will use
*
* Data members:
* - QString displayText: holds the text of what is to be displayed on the AED UI
* - StageOrderInSequence orderInSequence: stores the order that the stage is in
*
* Class functions:
* - void start(): The sequential walkthrough of an AEDStage of the AED.
* - StageOrderInSequence getOrderInSequence: A getter for the orderInSequence variable.
* - void updateDisplay(QString): A signal to the mainwindow to update the text display based on the QString passed in (the displayText variable is passed in).
* - void updateCompressionPicture(CompressionStatus):
* - void updateButtonStatus(BUTTON):
* - void nextStage(): A signal to the mainwindow to switch the stage.
*/

class AEDStage: public QObject {
    Q_OBJECT

    public:
        AEDStage();
        virtual ~AEDStage();
        virtual void start() = 0;
        StageOrderInSequence getOrderInSequence();

    protected:
        QString displayText;
        StageOrderInSequence orderInSequence;

    signals:
        void updateDisplay(QString);
        void updateCompressionPicture(CompressionStatus);
        void updateButtonStatus(BUTTON);
        void nextStage();
};
#endif
