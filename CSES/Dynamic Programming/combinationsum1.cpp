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

int recurr(int sum,vector<int>&coins,vector<long long>&dp){
    if(sum==0)return 1;
    else if(dp[sum]!=-1)return dp[sum];

    int ans=0,mod=1e9+7;
    for(int i=0;i<coins.size();i++){
        if(sum-coins[i]>=0){
            ans=(ans+recurr(sum-coins[i],coins,dp))%mod;
        }
    }return dp[sum]=ans;
}

int main(){
int n,x;cin>>n>>x;
vector<int>coins(n);
vector<long long>dp(x+1,-1);
for(int i=0;i<n;i++)cin>>coins[i];
cout<<recurr(x,coins,dp);
return 0;
}