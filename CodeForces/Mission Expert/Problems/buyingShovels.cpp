#include<bits/stdc++.h>
#define MP make_pair
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}

void solve(){
    int n,k;cin>>n>>k;

    int ans=n;
    for(int i=1;i*i<=n;i++){
        
        if(n%i==0){
            if(i<=k){
                ans=min(ans,n/i);
            }

            if(n/i<=k){
                ans=min(ans,i);
            }
        }
    }

    cout<<ans<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}