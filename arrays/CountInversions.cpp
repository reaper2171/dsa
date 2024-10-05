// Counting inversions pairs using merge sort algorithm
#include <bits/stdc++.h>
using namespace std;

int mergeSort(vector<int> & arr, int low, int high){
    int count = 0;
    if(low>=high)
        return count;
    int mid = (low + high)/2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid+1, high);
    count += merge(arr, low, mid, high);
    return count;
}

int countInversions(vector<int> &arr, int n){
    return mergeSort(arr, 0, n-1);
}