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

int dp[10];

int minCoins(vector<int>&coins,int sum){
    if(sum==0)return 0;
    if(dp[sum]!=-1)return dp[sum];
    int n=coins.size();
    int ans=INT32_MAX;
    for(int& coin:coins){
        if(coin<=sum){
            ans=min(ans,minCoins(coins,sum-coin)+1);
        }
    }return dp[sum]=ans;
}

int main(){
vector<int>coins={25,10,1};
memset(dp,-1,sizeof(dp));
int sum=30;
cout<<minCoins(coins,sum);
return 0;
}