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
vector<pair<int,int>>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i].second;
    cin>>arr[i].first;
}

sort(arr.begin(),arr.end());

int ans=1;
int last=arr[0].first;

for(int i=1;i<n;i++){
    
    if(arr[i].second>=last){
        ans++;
        last=arr[i].first;
    }
}

cout<<ans;
return 0;
}