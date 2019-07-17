#include "staffInfo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Staff *createStaffs(int num)
{
    struct Staff *staffs = (struct Staff *)malloc(sizeof(struct Staff) * num);
    int i = 0;
    for (i = 0; i < num; i++)
    {
        char *nameInit = "im Test Staff";
        staffs[i].name = nameInit;
    }
    return staffs;
}

void setStaffName(struct Staff *staffs, int index, char *name)
{
    staffs[index].name = name;
}

void showWannaDayOffList(enum dayOffType *askDayOff, int totalDays)
{
    bool IsFirstElement = true;
    printf("[");
    for (int i = 0; i < totalDays; i++)
    {
        if (askDayOff[i] != WORKING && askDayOff[i] != THIS_DAY_DOES_NOT_EXIST)
        {
            if (IsFirstElement == true)
            {
                printf("Day %d: %d", i + 1, askDayOff[i]); // [0] represent day1; [9] represent day 10
                IsFirstElement = false;
            }
            else
            {
                printf(", Day %d: %d", i + 1, askDayOff[i]);
            }
        }
    }
    printf("]\n");
}

void setStaffDayOff(struct Staff *staffs, int staffIndex, int day, enum dayOffType askDayOffType)
{
    day--; //day1 should be saved at [0]; day 10 should be saved at [9]
    staffs[staffIndex].wannaDayOffList[day] = askDayOffType;
}

void printStaffsWannaDayOffList(struct Staff staffs[], int totalStaffNum)
{
    for (int i = 0; i < totalStaffNum; i++)
    {
        printf("%s:", staffs[i].name);
        showWannaDayOffList(staffs[i].wannaDayOffList, MAX_DAYS_IN_ONE_MONTH);
    }
}

struct RequirmentInMonth *createRequirmentInMonth()
{
    struct RequirmentInMonth *requirmentInMonth = (struct RequirmentInMonth *)malloc(sizeof(struct RequirmentInMonth) * 1);

    for (int i = 0; i < MAX_DAYS_IN_ONE_MONTH; i++)
    {
        requirmentInMonth->staffsRequirment[i] = 0;
        requirmentInMonth->staffsCouldTakeDayOff[i] = 0;
    }
    return requirmentInMonth;
}

void setRequirmentMonth(struct RequirmentInMonth *requirmentInMonth, char *month, int totalDaysInMonth)
{
    requirmentInMonth->month = month;
    requirmentInMonth->totalDaysInMonth = totalDaysInMonth;
}

void printRequirment(struct RequirmentInMonth *requirmentInMonth)
{
    printf("Month: %s, %d days. \n", requirmentInMonth->month, requirmentInMonth->totalDaysInMonth);
}