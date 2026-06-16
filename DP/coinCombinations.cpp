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

int dp[300][1000000];

int solve(vector<int>&coins,int sum,int index){
    if(sum==0)return 1;//then we will add that way.
    if(index<0)return 0;//meaning there does not exist such combination.
    if(dp[index][sum]!=-1)return dp[index][sum];

    int ways=0;
    for(int coin_amount=0;coin_amount<=sum;coin_amount+=coins[index]){
        ways=solve(coins,sum-coin_amount,index-1);
    }
    return dp[index][sum]=ways;
}

int coinChange(vector<int>&coins,int sum){
    memset(dp,-1,sizeof(dp));
    cout<<solve(coins,sum,coins.size()-1);
}

int main(){
    int n,sum;cin>>n>>sum;
    vector<int>coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    cout<<coinChange(coins,sum);
return 0;
}