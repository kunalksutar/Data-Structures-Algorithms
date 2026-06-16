#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
using namespace std;

int main(){
int n;cin>>n;
int mod=1e9+7;
vector<ll>dp(n+1,0);
dp[0]=1;//basecase
for(int i=1;i<=n;i++){
    for(int j=1;j<=6;j++){
        if(i-j>=0)dp[i]=(dp[i]+dp[i-j])%mod;       
    }
}cout<<dp[n];
return 0;
}