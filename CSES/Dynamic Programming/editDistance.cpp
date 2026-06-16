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

int recurr(int i,int j,string&s1,string&s2,vector<vector<int>>&dp){
    if(i<0)return j+1;
    if(j<0)return i+1;
    else if(dp[i][j]!=-1)return dp[i][j];

    if(s1[i]==s2[j])return dp[i][j]=recurr(i-1,j-1,s1,s2,dp);
    int del_op=min(1+recurr(i-1,j,s1,s2,dp),1+recurr(i,j-1,s1,s2,dp));
    int replace_op=1+recurr(i-1,j-1,s1,s2,dp);
    return dp[i][j]=min(del_op,replace_op);
}

int main(){
string s1,s2;cin>>s1>>s2;
int n=s1.size(),m=s2.size();
vector<vector<int>>dp(n,vector<int>(m,-1));
cout<<recurr(n-1,m-1,s1,s2,dp);
return 0;
}