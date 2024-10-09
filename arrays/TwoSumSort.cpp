// Two sum if you can sort the array and ideal for returning YES or NO in return 
#include<bits/stdc++.h>
using namespace std;

string twoSum(vector<int> &nums, int target){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int left = 0, right = n-1;
    while(left < right){
        int sum = nums[left]+nums[right];
        if(sum == target)
            return "YES";
        else if(sum < target)
            left++;
        else
            right++;
    }
    return "NO";
}