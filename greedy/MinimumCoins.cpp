#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int> &coins, int sum) {
    int res = 0;
    for(auto coin: coins){
        res += sum/coin;
        sum = sum%coin;
    }
    if(sum != 0)
        return -1;
    else
        return res;
}