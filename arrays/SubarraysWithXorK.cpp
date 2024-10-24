// finding total no of subarrays having K as Xor
#include <bits/stdc++.h>
using namespace std;

int subarrayWithXorK(vector<int> &nums, int K){
    int n = nums.size(), count = 0;
    map<int, int> mpp;
    int xr = 0;
    mpp[xr]++;
    for(int i = 0; i<n; i++){
        xr = xr ^ nums[i];
        int x = xr ^ K;
        count += mpp[x];
        mpp[xr]++;
    }
    return count;
}