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
vector<int>prices(n+1),pages(n+1);
for(int i=1;i<=n;i++)cin>>prices[i];
for(int i=1;i<=n;i++)cin>>pages[i];
vector<vector<int>>dp(n+1,vector<int>(x+1,0));

for(int i=1;i<=n;i++){
    for(int budget=0;budget<=x;budget++){
        int take=0,notTake;
        if(budget>=prices[i]){
            take=pages[i]+dp[i-1][budget-prices[i]];
        }notTake=dp[i-1][budget];
        dp[i][budget]=max(take,notTake);
    }
}cout<<dp[n][x];
return 0;
}