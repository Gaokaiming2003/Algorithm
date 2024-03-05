#ifndef QUICKSORT_H
#define QUICKSORT_H
#include<iostream>
#include<vector>
using namespace std;

template<class T>
void quickSort(vector<T>& , int, int);

template<class T>
int medianThree(vector<T>&, int, int, int);
#endif