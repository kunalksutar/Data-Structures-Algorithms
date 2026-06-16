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
#define MP make_pair
const int INF=1e9;
using namespace std;

int main(){
int n;cin>>n;
vector<pair<int,pair<int,int>>>arr(n);
//          {start, {end,price}}
for(int i=0;i<n;i++){
    cin>>arr[i].first;
    cin>>arr[i].second.first;
    cin>>arr[i].second.second;
}

sort(arr.begin(),arr.end());
vector<int>dp(n+1);dp[n]=0;//base case
for(int i=n-1;i>=0;i--){
    int notTake=dp[i+1];
    int take;

    int curr_end=arr[i].second.first;
    //the below will give the index of the element that will start after 
    int index=upper_bound(arr.begin(),arr.end(),MP(curr_end,MP(INF,INF)))-arr.begin();
    take=arr[i].second.second+dp[index];

    dp[i]=max(notTake,take);
}cout<<dp[0];
return 0;
}//https://www.youtube.com/watch?v=lJAYDAhPOpI&t=7180s