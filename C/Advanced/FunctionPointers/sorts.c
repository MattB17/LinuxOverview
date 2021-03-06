#include <stdio.h>
// include header file
#include "sorts.h"

const int NUM_SORTS = 3;
// initialize array of sort_info structs
sort_info SORTS[] = {
  {.name = "bubble", .sort_func = bubble_sort},
  {.name = "insertion", .sort_func = insertion_sort},
  {.name = "selection", .sort_func = selection_sort}
};

void swap(int *arr, int index1, int index2) {
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
}

void bubble_sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 1; j < size - i; j++) {
      if (arr[j - 1] > arr[j]) {
        swap(arr, j - 1, j);
      }
    }
  }
}

void selection_sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    int current = i;
    for (int j = i; j < size; j++) {
      if (arr[current] > arr[j]) {
        current = j;
      }
    }swap(arr, i, current);
  }
}

void insertion_sort(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    for (int j = i + 1; j > 0 && arr[j - 1] > arr[j]; j--) {
      swap(arr, j - 1, j);
    }
  }
}
