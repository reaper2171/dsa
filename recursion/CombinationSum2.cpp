#include <bits/stdc++.h>
using namespace std;

void findCombo(int ind, int target, vector<int> &cand, vector<vector<int>> &res, vector<int> &ds){
    if(target == 0){
        res.push_back(ds);
        return;
    }
    for(int i = ind; i<cand.size(); i++){
        if(i>ind && cand[i]==cand[i-1])
            continue;
        if(cand[i]>target)
            break;
        ds.push_back(cand[i]);
        findCombo(i+1, target-cand[i], cand, res, ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& cand, int target) {    
    vector<vector<int>> res;
    vector<int> ds;
    sort(cand.begin(), cand.end());
    findCombo(0, target, cand, res, ds);
    return res;
}