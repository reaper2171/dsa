// Finding largest subarray with sum K using hashing 
// This is the most optimal solution if the array contains negative elements too
#include <bits/stdc++.h>
using namespace std;

int largestSub(vector<int> &nums, int k){
    int n = nums.size(), longest = -1;
    map<long long, int> mpp;
    long long sum = 0;
    for(int i = 0; i<n; i++){
        sum += nums[i];
        if(sum == k)
            longest = max(longest, i+1);
        long long rem = sum - k;
        if(mpp.find(rem)!=mpp.end()){
            longest = max(longest, i - mpp[rem]);
        }
        if(mpp.find(sum)==mpp.end())
            mpp[sum] = i;
    }
    return longest;
}