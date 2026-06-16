#include<cstdlib>
#include<iostream>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<list>
#include<deque>
#include<array>
#include<cassert>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
using namespace std;

bool searchMatrix(vector<vector<int>>&matrix,int target){
    int m=matrix.size();
    int n=matrix[0].size();
    int left=0;
    int right=m*n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(matrix[mid/m][mid%m]==target)return true;
        else if(matrix[mid/m][mid%m]<target)left=mid+1;
        else right=mid-1;
    }return false;
}

int main(){
    vector<vector<int>>mat={{1}};
    vector<int>vec={10,11,16,20};
    //cout<<binSearch(vec,17,0,3);
    cout<<searchMatrix(mat,1);
return 0;
}