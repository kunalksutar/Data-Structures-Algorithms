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
typedef long long ll;
using namespace std;


int main(){
int n;cin>>n;
int sum=(n*(n+1))/2,target=sum/2;
if(sum%2!=0){
    cout<<0;
    return 0;
}
int mod=1e9+7;int ans=0;
vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
dp[1][1]=1;dp[0][0]=1;
for(int i=2;i<=n;i++){
    for(int x=0;x<=target;x++){
        int notTake=dp[i-1][x];
        int take=0;
        if(x>=i)take=dp[i-1][x-i];
        dp[i][x]=(take+notTake)%mod;

    }
}cout<<dp[n][target];
return 0;
}