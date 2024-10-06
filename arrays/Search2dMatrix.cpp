// Searching a target in a 2D matrix by flattening it to a 1D
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int> &mat, int target){
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = n * m - 1;
    while(low<=high){
        int mid = (low+high)/2;
        int row = mid/m, col = mid%m;
        if(mat[row][col]==target)
            return true;
        else if(mat[row][col]<target)
            low = mid+1;
        else
            high = mid - 1;
    }
    return false;
}