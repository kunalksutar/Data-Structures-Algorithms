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

int recurr(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&dp){
    int n=grid.size();
    if(i==n || j==n || grid[i][j]=='*')return 0;
    else if(i==n-1&&j==n-1 && grid[n-1][n-1]=='.')return 1;
    else if(dp[i][j]!=-1)return dp[i][j];

    int mod=1e9+7;
    int right=recurr(i,j+1,grid,dp);
    int down=recurr(i+1,j,grid,dp);
    return dp[i][j]=(right+down)%mod;
}

int main(){
int n;cin>>n;
vector<vector<char>>grid(n,vector<char>(n));
vector<vector<int>>dp(n,vector<int>(n,-1));
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>grid[i][j];
    }
}cout<<recurr(0,0,grid,dp);
return 0;
}