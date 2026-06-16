#include<bits/stdc++.h>
#define MP make_pair
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}

int main(){

int n;cin>>n;
vector<pair<int,int>>arr;
for(int i=0;i<n;i++){
    int x,y;cin>>x>>y;
    arr.push_back({x,1});
    arr.push_back({y,-1});
}

sort(arr.begin(),arr.end());

int ans=0,curr=0;
for(int i=0;i<arr.size();i++){
    curr+=arr[i].second;
    ans=max(ans,curr);
}

cout<<ans;
return 0;
}