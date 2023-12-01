#ifndef CONSTANTS_H
#define CONSTANTS_H

const int MINIMUM_BATTERY_CAPACITY = 10;
typedef enum {PASS, FAIL} STATUS;
typedef enum {CPR, PEDI, UPPER, LOWER} BUTTON;
enum class StageOrderInSequence {
    RESPONSIVENESS_STAGE = 0,
    HELP_STAGE = 1,
    ELECTRODE_STAGE = 2,
    ANALYSIS_STAGE = 3,
    SHOCK_STAGE = 4,
    CPR_STAGE = 5
};

#endif
