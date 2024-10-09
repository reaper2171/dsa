// Optimal solution for finding longest consecutive sequence using hashset
#include <bits/stdc++.h>
using namespace std;

int longestConSeq(vector<int> &nums){
    int n = nums.size();
        if (n == 0)
            return 0;
        unordered_set<int> st;
        int longest = 1, count = 1;
        for (int i = 0; i < n; i++)
            st.insert(nums[i]);

        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int x = it;
                while (st.find(++x) != st.end()) {
                    count++;
                }
                longest = max(longest, count);
                count = 1;
            }
        }
        return longest;
}