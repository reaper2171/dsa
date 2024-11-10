#include <bits/stdc++.h>
using namespace std;

 int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int a = 0, d = 0, count = 0, minPlat = 0;
    while(a<arr.size() && d<dep.size()){
        if(arr[a]<=dep[d]){
            count++;
            a++;
        }
        else{
            count--;
            d++;
        }
        minPlat = max(minPlat, count);
    }
    return minPlat;
}