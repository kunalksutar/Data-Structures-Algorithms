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
int n,sum;cin>>n>>sum;

pair<int,int>ans={-1,-1};
map<int,int>mp;

for(int i=0;i<n;i++){
    int x;cin>>x;
    
    if(mp.find(sum-x)!=mp.end()){
        ans={i+1,mp[sum-x]+1};
    }
    
    mp[x]=i;
}

if(ans.ff==-1)cout<<"IMPOSSIBLE";
else cout<<ans.ff<<" "<<ans.ss;

return 0;
}