#include <bits/stdc++.h>
using namespace std;

void findCombo(int ind, int target, vector<int>& cand, vector<vector<int>>& res, vector<int>& ds) {
    if (ind >= cand.size()) {
        if (target == 0)
            res.push_back(ds);
        return;
    }

    if (cand[ind] <= target) {
        ds.push_back(cand[ind]);
        findCombo(ind, target - cand[ind], cand, res, ds);
        ds.pop_back();
    }
    findCombo(ind + 1, target, cand, res, ds);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> ds;
    findCombo(0, target, candidates, res, ds);
    return res;
}