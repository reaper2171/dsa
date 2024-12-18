#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int n = g.size(), m = s.size();
    int l = 0, r = 0;
    while(l<m && r<n){
        if(s[l] >= g[r])
            r++;
        l++;
    }
    return r;
}