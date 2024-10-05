// Finding missing and repeating number in an array using optimal XOR method
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeating(vector<int> &nums){
    int n = nums.size();
    int xr = 0;
    for(int i=0; i<n; i++){
        xr = xr ^ nums[i];
        xr = xr ^ (i+1);
    }
    int bitNo = 0;
    while(1){
        if((xr & (1<<bitNo))!=0)
            break;
        bitNo++;
    }

    int zero = 0, one = 0;
    for(int i=0; i<n; i++){
        if((nums[i] & (1<<bitNo))!=0)
            one = one ^ nums[i];
        else
            zero = zero ^ nums[i];
    }
    for(int i=1; i<=n; i++){
        if((i & (1<<bitNo))!=0)
            one = one ^ i;
        else
            zero = zero ^ i;
    }
    int count = 0;
    for(int i=0; i<n; i++)
        if(nums[i]==one)
            count++;
    
    if(count==2)    
        return {zero, one};
    return {one, zero};
}