// 4-sum using hashing
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                set<long long> hash;
                for(int k = j+1; k<n; k++){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    // we dont necessarily need to do explicitly do type conversion here
                    // as implicit type casting will happen as sum is long long
                    long long fourth = (long long)target - sum;
                    if(hash.find(fourth)!=hash.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hash.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> res {st.begin(), st.end()};
        return res;
    }