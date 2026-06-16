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

int dp[10000000];

int cost(int h[],int i,int k){//indexing from {1,2,3,...}
    if(i==1)return 0;//since the cost to reach index 1 is 0.
    //it is simple to understand that the code after this will only execute if and only if,
    //i > 1.
    if(dp[i]!=-1) return dp[i];
    else{
        int totalCost=INT32_MAX;
        for(int j=1;j<=k;j++)
            if(i-j>0)totalCost=min(totalCost,cost(h,i-k,k)+abs(h[i]-h[i-k]));//we don't have to worry if i-1 is zero or not.

        return dp[i]=totalCost;
    }
}

int main(){
int n,k;cin>>n>>k;
int h[n];
memset(dp,-1,sizeof(dp));
for(int i=0;i<n;i++)cin>>h[i];
cout<<cost(h,n,k);
return 0;
}