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

int dp[1000000];

int solve(vector<int>&coins,int sum){
    if(sum==0)return 0;
    if(dp[sum]!=-1)return dp[sum];
    int ans=INT32_MAX;
    for(int coin:coins)
        if(coin<=sum){
            ans=min(ans,solve(coins,sum-coin)+1);
        }
    return dp[sum]=ans;
}

int coinChange(vector<int>&coins,int sum){
    memset(dp,-1,sizeof(dp));
    int ans=solve(coins,sum);
    return ans==INT32_MAX?-1:ans;
}

int main(){
    int n,sum;cin>>n>>sum;
    vector<int>coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    cout<<coinChange(coins,sum);
return 0;
}