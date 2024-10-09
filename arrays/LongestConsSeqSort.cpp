// Finding longest consecutive sequence using sorting
#include <bits/stdc++.h>
using namespace std;

int longestConSeq(vector<int> &nums){
    int n = nums.size();
        if (n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int longest = 1, last = nums[0], count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == last + 1) {
                count++;
                last = nums[i];
            } else if (nums[i] != last) {
                count = 1;
                last = nums[i];
            }
            // update max at every iteration otherwise the loop may end after crossing n value
            longest = max(longest, count);
        }
        return longest;
}