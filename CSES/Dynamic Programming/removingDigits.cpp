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
int n;cin>>n;
vector<int>dp(n+1);dp[0]=0;

for(int i=1;i<=n;i++){
    int temp=i;
    int ans=1e9;
    while(temp!=0){
        int digit=temp%10;
        temp=temp/10;
        if(digit==0)continue;
        ans=min(ans,1+dp[i-digit]);
    }dp[i]=ans;
}cout<<dp[n];


return 0;
}