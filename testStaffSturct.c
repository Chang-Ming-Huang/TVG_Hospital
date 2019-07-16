#include "staffInfo.h"
#include "testStaffStruct.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct RequirmentInMonth *requirmentInMonth = CreateRequirmentInMonth();
    int totalStaffNum = 3;
    struct Staff *staffs = CreateStaffs(totalStaffNum);

    setRequirment(requirmentInMonth);
    setUserInfo(staffs, requirmentInMonth);

    PrintRequirment(requirmentInMonth);
    PrintStaffsAskDayOffRecords(staffs, totalStaffNum);

    return 0;
}

void setRequirment(struct RequirmentInMonth *requirmentInMonth)
{
    SetRequirmentMonth(requirmentInMonth, "JULY", 31);
    //SetRequirmentMonth(requirmentInMonth, "FEB", 28);
}

void setUserInfo(struct Staff *staffs, struct RequirmentInMonth *requirmentInMonth)
{
    int staffIndex = 0;
    char *name = "Lee";
    SetStaffName(staffs, staffIndex, name);
    setDefultDayOffValue(staffs, staffIndex, requirmentInMonth->totalDaysInMonth);
    SetStaffDayOff(staffs, staffIndex, 2, RED_LINE);
    SetStaffDayOff(staffs, staffIndex, 5, GREEN_LINE);
    SetStaffDayOff(staffs, staffIndex, 7, VACATION_RESERVATION);

    staffIndex++;
    name = "Wang";
    SetStaffName(staffs, staffIndex, name);
    setDefultDayOffValue(staffs, staffIndex, requirmentInMonth->totalDaysInMonth);
    SetStaffDayOff(staffs, staffIndex, 3, RED_LINE);
    SetStaffDayOff(staffs, staffIndex, 4, GREEN_LINE);
    SetStaffDayOff(staffs, staffIndex, 12, VACATION_RESERVATION);

    staffIndex++;
    name = "Chang";
    SetStaffName(staffs, staffIndex, name);
    setDefultDayOffValue(staffs, staffIndex, requirmentInMonth->totalDaysInMonth);
    SetStaffDayOff(staffs, staffIndex, 11, RED_LINE);
    SetStaffDayOff(staffs, staffIndex, 12, GREEN_LINE);
    SetStaffDayOff(staffs, staffIndex, 18, VACATION_RESERVATION);
}

void setDefultDayOffValue(struct Staff *staffs, int staffIndex, int endDayOfMonth)
{

    for (int day = 0; day < endDayOfMonth; day++)
    {
        SetStaffDayOff(staffs, staffIndex, day, WORKING);
    }

    for (int daysDoesNotExist = endDayOfMonth + 1; daysDoesNotExist <= MAX_DAYS_IN_ONE_MONTH; daysDoesNotExist++)
    {
        SetStaffDayOff(staffs, staffIndex, daysDoesNotExist, THIS_DAY_DOES_NOT_EXIST);
    }
}
