// Counting reverse pairs i.e. i<j && a[i]>2*a[j]
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low, right = mid+1;
    while(left <= mid && right <= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
        temp.push_back(arr[left++]);
    while(right<=high)
        temp.push_back(arr[right++]);
}

int countPairs(vector<int> &arr, int low, int mid, int high){
    int cnt = 0, right = mid+1;
    for(int i=low; i<=mid; i++){
        while(right<=high && arr[i]>2*arr[right])
            right++;
        cnt += right - (mid+1);
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low>=high)
        return cnt;
    int mid = (low + high)/2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int reversePairs(vector<int> &arr, n){
    return mergeSort(arr, 0, n-1);
}