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

int calPath(int m, int n,int dp[102][102]){
    if(dp[m][n]!=-1)return dp[m][n];
    else if(m==1 && n==1)return dp[m][n]=1;
    else if(m==2 && n==2)return dp[m][n]=2;
    else if(n==1||m==1)return dp[m][n]=1;
    else return dp[m][n]=calPath(m-1,n,dp)+calPath(m,n-1,dp);
}

int uniquePaths(int m,int n){
    int dp[102][102];
    memset(dp,-1,sizeof(dp));
    return calPath(m,n,dp);
}

int main(){
    cout<<uniquePaths(3,7);
return 0;
}