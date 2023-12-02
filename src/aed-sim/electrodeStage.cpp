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

void ElectrodeStage::applyCprPads(){
    updateDisplay("ADULT PADS.");

    qDebug() << "User uses the scissors to cut open the victim's shirt.";
    QThread::sleep(2);
    qDebug() << "User checkes if the victim is dry.";
    QThread::sleep(2);
    qDebug() << "User unpacks and unfolds the CPR-D-padz";
    QThread::sleep(2);
    qDebug() << "User places sensor in the middle of victims breastbone.";

    updateButtonStatus(CPR);
    updateButtonStatus(PEDI);
    updateButtonStatus(UPPER);
    updateButtonStatus(LOWER);
}

void ElectrodeStage::applyPediPads(Victim* victim){
    updateDisplay("PEDIATRIC PADS.");

    qDebug() << "User uses the scissors to cut open the victim's shirt.";
    QThread::sleep(2);
    qDebug() << "User checkes if the victim is dry.";
    QThread::sleep(2);
    qDebug() << "User unpacks and unfolds the Pedi-padz";

    connectPads();
    updateButtonStatus(CPR);
    updateButtonStatus(PEDI);
    updateButtonStatus(UPPER);
    updateButtonStatus(LOWER);
    victim->setIsChild();
}

void ElectrodeStage::applyUpperPad(Victim* victim){
    if(victim->getIsChild()){
        qDebug() << "User removes the round electrode from its backing and place it onto the victim’s chest.";
        QThread::sleep(2);
        qDebug() << "User place your hand on the electrode edge and, using the other hand, rolls the electrode onto the victim’s chest, pushing out any air.";
        QThread::sleep(2);
    }else{
        // There is a 15% chance the victim has a pacemaker
        if(victim->getHasPacemaker()){
            qDebug() << "VICTIM HAS A PACEMAKER.";
            QThread::sleep(2);
            qDebug() << "User places the electode at an angle to avoid placing them over the device.";
            QThread::sleep(2);
            qDebug() << "User ensures CPR sensor maintains position over lower half of the breastbone.";
        }

        qDebug() << "User presses down the CPR sensor with right hand to adhere electrode to skin, pulling the number 2 tab to peel back protective backing.";
        QThread::sleep(2);
        qDebug() << "User presses down the electrode from the center out.";
    }

    updateButtonStatus(UPPER);
    victim->applyUpperPad();

    if(victim->getIsLowerPadOn()){
        nextStage();
    }
}

void ElectrodeStage::applyLowerPad(Victim* victim){
    if(victim->getIsChild()){
        qDebug() << "User rolls the victim onto their chest.";
        QThread::sleep(2);
        qDebug() << "User removes the square electrode from its backing and place it on the victim’s back.";
        QThread::sleep(2);
        qDebug() << "User place your hand on the electrode edge and, using the other hand, rolls the electrode onto the victim’s chest, pushing out any air.";
        QThread::sleep(2);
        qDebug() << "User rolls the victim onto their back.";
    }else{
        // There is a 35% chance the victim is large
        if(victim->getIsLarge()){
            qDebug() << "VICTIM IS LARGE.";
            QThread::sleep(2);
            qDebug() << "User tears lower pad at perforated line and extends it.";
            QThread::sleep(2);
            qDebug() << "User places the pad slightly to the victim's left and below their left breast.";
            QThread::sleep(2);
        }
        qDebug() << "User presses down the CPR sensor with right hand to adhere electrode to skin, pulling the number 2 tab to peel back protective backing.";
        QThread::sleep(2);
        qDebug() << "User presses the the electrode from the center out.";
    }

    updateButtonStatus(LOWER);
    victim->applyLowerPad();

    if(victim->getIsUpperPadOn()){
        nextStage();
    }
}
