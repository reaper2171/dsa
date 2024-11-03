#include <bits/stdc++.h>
using namespace std;

bool comp(Job a, Job b){
    return a.profit>b.profit;
}
vector<int> JobScheduling(Job jobs[], int n) {
    sort(jobs, jobs+n, comp);
        
    int maxD = 0;
    for(int i = 0; i<n; i++)
        maxD = max(maxD, jobs[i].deadline);
            
    int hash[maxD+1], profit = 0, count = 0;
    for(int i=0; i<=maxD; i++)
        hash[i]=-1;
        
    for(int i = 0; i<n; i++){
        for(int j = jobs[i].deadline; j>0; j--){
            if(hash[j]==-1){
                hash[j] = jobs[i].id;
                profit += jobs[i].profit;
                count++;
                break;
            }
        }
    }
    return {count, profit};
}