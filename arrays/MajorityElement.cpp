// Finding majority element (>n/2) using Moore's voting algorithm
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums){
    int n = nums.size(), count = 0, elem = -1;
    for(int i=0; i<n; i++){
        if(count == 0){
            count = 1;
            elem = nums[i];
        }
        else if(nums[i]==elem)
            count++;
        else
            count--;
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        if(nums[i]==elem)
            cnt++;
    }
    if(cnt>(n/2))
        return elem;
    return -1;
}