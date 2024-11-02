#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& arr) {
    int n = arr.size();
    int l = 0, r = n-1, lmax = 0, rmax = 0, area = 0;
    while(l != r){
        if(arr[l]<arr[r]){
            if(lmax >= arr[l])
                area += min(lmax, arr[r]) - arr[l];
            else
                lmax = arr[l];
            l++;
        }
        else{
            if(rmax >= arr[r])
                area += min(rmax, arr[l]) - arr[r];
            else
                rmax = arr[r];
            r--;
        }
    }  
    return area;
}