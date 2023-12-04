#include "electrodeStage.h"

ElectrodeStage::ElectrodeStage() {
    displayText = "ATTACH DEFIB PADS TO PATIENT'S BARE CHEST.";
    orderInSequence = StageOrderInSequence::ELECTRODE_STAGE;
}

ElectrodeStage::~ElectrodeStage() { }

void ElectrodeStage::start() {
    updateDisplay(displayText);
}

void ElectrodeStage::applyCprPads() {
    updateDisplay("ADULT PADS.");

    qDebug() << "User uses the scissors to cut open the victim's shirt.";
    QThread::msleep(500);
    qDebug() << "User checkes if the victim is dry.";
    QThread::msleep(500);
    qDebug() << "User unpacks and unfolds the CPR-D-padz";
    QThread::msleep(500);
    qDebug() << "User places sensor in the middle of victims breastbone.";

    updateButtonStatus(CPR);
    updateButtonStatus(PEDI);
    updateButtonStatus(UPPER);
    updateButtonStatus(LOWER);
}

void ElectrodeStage::applyPediPads(Victim* victim) {
    updateDisplay("PEDIATRIC PADS.");

    qDebug() << "User uses the scissors to cut open the victim's shirt.";
    QThread::msleep(500);
    qDebug() << "User checkes if the victim is dry.";
    QThread::msleep(500);
    qDebug() << "User unpacks and unfolds the Pedi-padz";

    connectPads();
    updateButtonStatus(CPR);
    updateButtonStatus(PEDI);
    updateButtonStatus(UPPER);
    updateButtonStatus(LOWER);
    victim->setIsChild();
}

void ElectrodeStage::applyUpperPad(Victim* victim) {
    if (victim->getIsChild()) {
        qDebug() << "User removes the round electrode from its backing and place it onto the victim’s chest.";
        QThread::msleep(500);
        qDebug() << "User place your hand on the electrode edge and, using the other hand, rolls the electrode onto the victim’s chest, pushing out any air.";
        QThread::msleep(500);
    }
    else {
        // There is a 15% chance the victim has a pacemaker
        if (victim->getHasPacemaker()) {
            qDebug() << "User determines victim has a pacemaker.";
            QThread::msleep(500);
            qDebug() << "User places the electode at an angle to avoid placing them over the device.";
            QThread::msleep(500);
            qDebug() << "User ensures CPR sensor maintains position over lower half of the breastbone.";
        }
        qDebug() << "User presses down the CPR sensor with right hand to adhere electrode to skin, pulling the number 2 tab to peel back protective backing.";
        QThread::msleep(500);
        qDebug() << "User presses down the upper electrode from the center out.";
    }

    updateButtonStatus(UPPER);
    victim->applyUpperPad();

    if (victim->getIsLowerPadOn()) {
        nextStage();
    }
}

void ElectrodeStage::applyLowerPad(Victim* victim) {
    if (victim->getIsChild()) {
        qDebug() << "User rolls the victim onto their chest.";
        QThread::msleep(500);
        qDebug() << "User removes the square electrode from its backing and place it on the victim’s back.";
        QThread::msleep(500);
        qDebug() << "User place your hand on the electrode edge and, using the other hand, rolls the electrode onto the victim’s chest, pushing out any air.";
        QThread::msleep(500);
        qDebug() << "User rolls the victim onto their back.";
    }
    else {
        // There is a 35% chance the victim is large
        if (victim->getIsLarge()) {
            qDebug() << "User determines victim is large.";
            QThread::msleep(500);
            qDebug() << "User tears lower pad at perforated line and extends it.";
            QThread::msleep(500);
            qDebug() << "User places the pad slightly to the victim's left and below their left breast.";
            QThread::msleep(500);
        }
        qDebug() << "User presses down the CPR sensor with right hand to adhere electrode to skin, pulling the number 3 tab to peel back protective backing.";
        QThread::msleep(500);
        qDebug() << "User presses the the lower electrode from the center out.";
    }

    updateButtonStatus(LOWER);
    victim->applyLowerPad();

    if (victim->getIsUpperPadOn()) {
        nextStage();
    }
}
