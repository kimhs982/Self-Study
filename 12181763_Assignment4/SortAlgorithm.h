// Sorting Algorithm의 함수 원형

#pragma once
#include "ArrayVector.h"
#include "DataSet.h"

void insertionSort(int, ArrayVector&);
void insertionSort(int, DataSet&);

void selectionSort(int, ArrayVector&);
void selectionSort(int, DataSet&);

void mergeSort(int, ArrayVector&);
void mergeSort(int, DataSet&);

void inPlaceQuickSort(ArrayVector&, int, int);
void inPlaceQuickSort(DataSet&, int, int);