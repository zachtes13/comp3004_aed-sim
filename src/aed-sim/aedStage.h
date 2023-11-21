
#ifndef AEDSTAGE_H
#define AEDSTAGE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class AEDStage {

    public:

        //constructor
        AEDStage(string displayText, int orderInSequence);

        //destructor
        virtual ~AEDStage();

    protected:

        string displayText;
        int orderInSequence;

};
#endif
