// Finding majority element (>n/3)
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums){
    int n = nums.size();
    int elem1 = -1, elem2 = -1, cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n; i++){
        if(cnt1 == 0 && nums[i]!=elem2){
            cnt1++;
            elem1 = nums[i];
        }
        else if(cnt2 == 0 && nums[i]!=elem1){
            cnt2++;
            elem2 = nums[i];
        }
        else if(nums[i] == elem1)
            cnt1++;
        else if(nums[i] == elem2)
            cnt2++;
        else
            cnt--; cnt2--;
    }
    cnt1 = 0, cnt2 = 0;
    vector<int> res;
    for(int i=0; i<n; i++){
        if(nums[i]==elem1)
            cnt1++;
        else if(nums[i]==elem2)
            cnt2++;
    }
    if(cnt1>(n/3))
        res.push_back(elem1);
    if(cnt2>(n/3))
        res.push_back(elem2);
    return sort(res.begin(), res.end());
}