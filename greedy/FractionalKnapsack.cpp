#include <bits/stdc++.h>
using namespace std;

struct item{
    int value;
    int weight;
};

static bool comp(item a, item b){
    double x = (double)a.value/(double)a.weight;
    double y = (double)b.value/(double)b.weight;
    return x>y;
}
    
// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(vector<int>& values, vector<int>& weights, int w) {
    vector<item> items;
    for(int i = 0; i<values.size(); i++)
        items.push_back({values[i], weights[i]});
            
    sort(items.begin(), items.end(), comp);
    int i = 0;
    double res = 0.00;
    while(w>0 && i<items.size()){
        double perUnitVal = (double)items[i].value/(double)items[i].weight;
        if(w>=items[i].weight){
            res += items[i].value;
            w -= items[i].weight; 
        }
        else{
            res += w * perUnitVal;
            break;
        }
        i++;
    }
    return res;
}