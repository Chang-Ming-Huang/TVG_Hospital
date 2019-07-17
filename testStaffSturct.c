#include "staffInfo.h"
#include "testStaffStruct.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct RequirmentInMonth *requirmentInMonth = createRequirmentInMonth();
    int totalStaffNum = 3;
    struct Staff *staffs = createStaffs(totalStaffNum);

    setRequirment(requirmentInMonth);
    setUserInfo(staffs, requirmentInMonth);

    printMeaningOfEnum();
    printRequirment(requirmentInMonth);
    printStaffsAskDayOffRecords(staffs, totalStaffNum);

    return 0;
}

void setRequirment(struct RequirmentInMonth *requirmentInMonth)
{
    setRequirmentMonth(requirmentInMonth, "JULY", 31);
    //setRequirmentMonth(requirmentInMonth, "FEB", 28);
}

void setUserInfo(struct Staff *staffs, struct RequirmentInMonth *requirmentInMonth)
{
    int staffIndex = 0;
    char *name = "Lee";
    setStaffName(staffs, staffIndex, name);
    setDefultDayOffValue(staffs, staffIndex, requirmentInMonth->totalDaysInMonth);
    setStaffDayOff(staffs, staffIndex, 2, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 3, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 8, GREEN_LINE);
    setStaffDayOff(staffs, staffIndex, 14, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 15, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 20, GREEN_LINE);
    setStaffDayOff(staffs, staffIndex, 25, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 29, RED_LINE);

    staffIndex++;
    name = "Wang";
    setStaffName(staffs, staffIndex, name);
    setDefultDayOffValue(staffs, staffIndex, requirmentInMonth->totalDaysInMonth);
    setStaffDayOff(staffs, staffIndex, 6, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 11, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 12, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 18, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 19, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 24, GREEN_LINE);
    setStaffDayOff(staffs, staffIndex, 25, RED_LINE);

    staffIndex++;
    name = "Chang";
    setStaffName(staffs, staffIndex, name);
    setDefultDayOffValue(staffs, staffIndex, requirmentInMonth->totalDaysInMonth);
    setStaffDayOff(staffs, staffIndex, 6, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 12, RED_LINE);
    setStaffDayOff(staffs, staffIndex, 18, VACATION_RESERVATION);
    setStaffDayOff(staffs, staffIndex, 19, VACATION_RESERVATION);
    setStaffDayOff(staffs, staffIndex, 20, VACATION_RESERVATION);
    setStaffDayOff(staffs, staffIndex, 21, VACATION_RESERVATION);
    setStaffDayOff(staffs, staffIndex, 22, VACATION_RESERVATION);
    setStaffDayOff(staffs, staffIndex, 23, VACATION_RESERVATION);
    setStaffDayOff(staffs, staffIndex, 28, RED_LINE);
}

void setDefultDayOffValue(struct Staff *staffs, int staffIndex, int endDayOfMonth)
{

    for (int day = 0; day < endDayOfMonth; day++)
    {
        setStaffDayOff(staffs, staffIndex, day, WORKING);
    }

    for (int daysDoesNotExist = endDayOfMonth + 1; daysDoesNotExist <= MAX_DAYS_IN_ONE_MONTH; daysDoesNotExist++)
    {
        setStaffDayOff(staffs, staffIndex, daysDoesNotExist, THIS_DAY_DOES_NOT_EXIST);
    }
}

void printMeaningOfEnum()
{
    printf("================================\n");
    printf("Here are the meaning of Enum:\n");
    printf("0: go to work (deafult). It won't show later.\n1: staff ask for day off\n");
    printf("2: staff has higher priority to take day off(e.g. business trip, go to school)\n3: reservation of vacation\n");
    printf("================================\n");
}