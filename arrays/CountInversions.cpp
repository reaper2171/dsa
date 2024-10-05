// Counting inversions pairs using merge sort algorithm
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high){
    int count = 0;
    int left = low, right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            count += mid - left + 1;
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
        temp.push_back(arr[right++]);

    return count;
}

int mergeSort(vector<int> &arr, int low, int high){
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