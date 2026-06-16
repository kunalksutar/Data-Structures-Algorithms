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

int main(){
int n,x;cin>>n>>x;
int mod=1e9+7;
vector<int>coins(n+1);
vector<vector<int>>dp(n+1,vector<int>(x+1,0));
for(int i=1;i<=n;i++)cin>>coins[i];

for(int i=1;i<=n;i++){
    for(int sum=0;sum<=x;sum++){
        if(sum==0)dp[i][sum]=1;
        else{
            int take=(sum>=coins[i])?dp[i][sum-coins[i]]:0;
            int notTake=(i==1)?0:dp[i-1][sum];
            dp[i][sum]=(take+notTake)%mod;
        }
    }
}cout<<dp[n][x];
return 0;
}