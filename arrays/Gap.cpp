#include <bits/stdc++.h>
using namespace std;

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2){
    if(arr1[ind1]> arr2[ind2])
        swap(arr1[ind1], arr2[ind2]);
}

void mergeSortedArrays(long long arr1[], long long arr2[], int n, int m){
    int len = n+m;
    int gap = len/2 + len%2; // ceil alternative
    while(gap>0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            // case where both left and right are in different arrays
            if(left<n && right>=n){
                swapIfGreater(arr1, arr2, left, right-n);
            }
            // case where both left and right are in arr2
            else if(left>=n){
                swapIfGreater(arr2, arr2, left-n, right-n);
            }
            // case where both left and right are in arr1
            else{
                swapIfGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }
        if(gap == 1)
            break;
        gap = gap/2 + gap%2;
    }
}