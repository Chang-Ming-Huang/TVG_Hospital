#include "greeter.h"
#include "staffInfo.h"
#include <stdio.h>
#include <stdlib.h>

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
