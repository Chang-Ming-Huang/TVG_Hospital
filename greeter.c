#include "greeter.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int greet(struct Staff *g, char *out)
{
  int n;
  n = sprintf(out, "Greetings, %s from %d! We come in peace :)", g->name, g->startWorkingYear);

  return n;
}

void PrintArray(int arr[], int len)
{
  int i = 0;
  printf("[");
  for (i = 0; i < len; i++)
  {
    if (i == len - 1)
      printf("%d", arr[i]);
    else
      printf("%d ", arr[i]);
  }
  printf("]\n");
}

int *CreateArray(int len)
{
  int *arr = (int *)malloc(sizeof(int) * len);
  int i = 0;
  for (i = 0; i < len; i++)
  {
    arr[i] = i;
  }
  return arr;
}

void SetArrValue(int *arr, int index, int value)
{
  arr[index] = value;
}

struct Staff *CreateStaffs(int num)
{
  struct Staff *staffs = (struct Staff *)malloc(sizeof(struct Staff) * num);
  int i = 0;
  for (i = 0; i < num; i++)
  {
    char *nameInit = "imStaff";
    staffs[i].name = nameInit;
  }
  return staffs;
}

void SetStaffName(struct Staff *staffs, int index, char *name)
{
  staffs[index].name = name;
}

void ShowAskDayOff(enum dayOffType *askDayOff, int totalDays)
{
  bool IsFirstElement = true;
  printf("[");
  for (int i = 0; i < totalDays; i++)
  {
    if (askDayOff[i] != WORKING)
    {
      if (IsFirstElement == true)
      {
        printf("Day %d: %d", i, askDayOff[i]);
        IsFirstElement = false;
      }
      else
      {
        printf(", Day %d: %d", i, askDayOff[i]);
      }
    }
  }
  printf("]\n");
}

void SetStaffDayOff(struct Staff *staffs, int staffIndex, int day, enum dayOffType askDayOffType)
{
  staffs[staffIndex].askDayOff[day] = askDayOffType;
}

//TODO
void PrintStaffsAskDayOffRecords(struct Staff staffs[], int totalStaffNum)
{
  int totalDays = 31;
  for (int i = 0; i < totalStaffNum; i++)
  {
    printf("%s:", staffs[i].name);
    ShowAskDayOff(staffs[i].askDayOff, totalDays);
  }
}

struct RequirmentInMonth *CreateRequirmentInMonth()
{
  struct RequirmentInMonth *requirmentInMonth = (struct RequirmentInMonth *)malloc(sizeof(struct RequirmentInMonth) * 1);

  for (int i = 0; i < 31; i++)
  {
    requirmentInMonth->staffsRequirment[i] = 0;
    requirmentInMonth->staffsCouldTakeDayOff[i] = 0;
  }
  return requirmentInMonth;
}

void SetRequirmentMonth(struct RequirmentInMonth *requirmentInMonth, char *month, int totalDaysInMonth)
{
  requirmentInMonth->month = month;
  requirmentInMonth->totalDaysInMonth = totalDaysInMonth;
}

void PrintRequirment(struct RequirmentInMonth *requirmentInMonth)
{
  printf("Month: %s, %d days. \n", requirmentInMonth->month, requirmentInMonth->totalDaysInMonth);
}