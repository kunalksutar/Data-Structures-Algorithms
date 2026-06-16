#include<bits/stdc++.h>
#define MP make_pair
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}
#define mp make_pair
#define ff first
#define ss second

int main(){
int n;cin>>n;
vector<pair<int,int>>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i].ff;
    arr[i].ss=i;
}

sort(arr.begin(),arr.end());

int ans=0;
int prev=n;

for(int i=0;i<n;i++){

    if(arr[i].ss<prev){
        ans++;
    }

    prev=arr[i].ss;
}


cout<<ans;
return 0;
}