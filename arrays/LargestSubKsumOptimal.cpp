// This is the optimal solution for finding the longest subarray if the array contains only
// postive and 0 as elements
#include <bits/stdc++.h>
using namespace std;

int largestSub(vector<int> &nums, int K){
    int n = nums.size(), longest = 0;
    int left = 0, right = 0;
    long long sum = nums[0];
    while(right<n){
        while(left<=right && sum>K){
            sum -= nums[left];
            left++;
        }
        if(sum == K)
            longest = max(longest, left - right + 1);
        right++;
        if(right<n)
            sum += nums[right];
    }
    return longest;
}