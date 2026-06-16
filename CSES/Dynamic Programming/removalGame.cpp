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

ll recurr(int left,int right,vector<int>&arr,vector<vector<ll>>&dp){
    if(left==right)return arr[left];
    else if(left+1==right)return max(arr[left],arr[right]);
    else if(dp[left][right]!=-1)return dp[left][right];

    //we can either take the left most element or the right most element in the array
    //whatever side we take, from there the second player will pick an element such that 
    //in the next turn, the first player will get a smaller sum.
    //hence we call for the minimum
    //https://www.youtube.com/watch?v=W1k8fXFIHTY
    ll leftMax=arr[left]+min(recurr(left+1,right-1,arr,dp),recurr(left+2,right,arr,dp));
    ll rightMax=arr[right]+min(recurr(left+1,right-1,arr,dp),recurr(left,right-2,arr,dp));

    return dp[left][right]=max(leftMax,rightMax);
}

int main(){
int n;cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++)cin>>arr[i];
vector<vector<ll>>dp(n,vector<ll>(n,-1));
cout<<recurr(0,n-1,arr,dp);
return 0;
}