// Two sum using hash set and returning the indices of the given numbers
#include <bits/stdc++.h>
using namespace std;

pair<int,int> twoSum(vector<int> &nums, int target){
    pair<int, int> res;
    int n = nums.size();
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        if(mpp.find(target - nums[i])!=mpp.end()){
            res.first = i;
            res.second = mpp[target-nums[i]];
            return res;
        }
        mpp[nums[i]]=i;
    }
    res.first = -1;
    res.second = -1;
    return res;
}