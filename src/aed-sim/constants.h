#ifndef CONSTANTS_H
#define CONSTANTS_H

const int MINIMUM_BATTERY_CAPACITY = 10;
const int MAXIMUM_HEART_RATE = 251;
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
typedef enum {
    BLANK,
    NORMAL,
    VTACH,
    VFIB,
    ASYSTOLE
} HEART_RATE;
enum class CompressionStatus {
    GOOD_COMPRESSIONS = 1,
    BAD_COMPRESSIONS = 2,
    NO_COMPRESSIONS = 3
};
#endif
