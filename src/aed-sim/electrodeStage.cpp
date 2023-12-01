#include "electrodeStage.h"

ElectrodeStage::ElectrodeStage() {
    displayText = "ATTACH DEFIB PADS TO PATIENT'S BARE CHEST.";
    orderInSequence = StageOrderInSequence::ELECTRODE_STAGE;
}

ElectrodeStage::~ElectrodeStage() { }

void ElectrodeStage::start() {
    updateDisplay(displayText);
    QThread::sleep(2);
    qDebug() << "User applies electrodes.";
    QThread::sleep(2);
}

void ElectrodeStage::applyCprPads(Victim* victim){
    updateDisplay("ADULT PADS.");
    updateUIButton(CPR);
    updateUIButton(PEDI);
}

void ElectrodeStage::applyPediPads(Victim* victim){
    updateDisplay("PEDIATRIC PADS.");
    updateUIButton(CPR);
    updateUIButton(PEDI);
    victim->setIsChild();
}

void ElectrodeStage::applyUpperPad(Victim* victim){
    qDebug() << "IN APPLY UPPER PADS";
    updateUIButton(UPPER);
    victim->applyUpperPad();
}

void ElectrodeStage::applyLowerPad(Victim* victim){
    qDebug() << "IN APPLY LOWER PADS";
    updateUIButton(LOWER);
    victim->applyLowerPad();
}
