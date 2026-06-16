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

int dp[4010];

int solve(int sum,vector<int>&strips){
    if(sum==0)return 0;
    if(dp[sum]!=-1)return dp[sum];
    int ans=INT32_MIN;
    for(int strip:strips)
        if(sum-strip>=0)
            ans=max(ans,solve(sum-strip,strips)+1);
    return dp[sum]=ans;
}

int main(){
int n,a,b,c;cin>>n>>a>>b>>c;
memset(dp,-1,sizeof(dp));
vector<int>strips={a,b,c};
cout<<solve(n,strips)<<endl;
return 0;
}