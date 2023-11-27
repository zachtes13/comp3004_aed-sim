#ifndef AEDSTAGE_H
#define AEDSTAGE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <QString>
#include <QObject>
#include <QDebug>

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

    protected:
        QString displayText;
        int orderInSequence;

    signals:
        void updateDisplay(QString);

};
#endif
