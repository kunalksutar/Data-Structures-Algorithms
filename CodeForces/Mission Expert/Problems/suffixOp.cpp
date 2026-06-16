#include<bits/stdc++.h>
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
#define ff first
#define ss second
#define MP make_pair
#define nline endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
bool rev(ll&a,ll&b){return a>b;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}
vector<ll>seive(int n){//will return all the prime numbers till n(included)
   vector<ll>res;
   vector<int>arr(n+1,0);
   for(int i=2;i<=n;i++){
       if(arr[i]==0){
           res.push_back(i);
           for(int j=i*i;j<=n;j+=i){
               arr[i]=1;
           }
       }
   }return res;
}

void solve(){
    int n;cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    ll damage=0;

    damage=max(damage,(ll)abs(arr[1]-arr[0]));
    damage=max(damage,(ll)abs(arr[n-1]-arr[n-2]));

    for(int i=1;i<n-1;i++){
       damage=max(damage,(ll)(abs(arr[i]-arr[i-1])+abs(arr[i+1]-arr[i])-abs(arr[i+1]-arr[i-1])));
    }

    ll ans=0;
    for(int i=1;i<n;i++){
        ans+=abs(arr[i]-arr[i-1]);
    }

    cout<<ans-damage<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}