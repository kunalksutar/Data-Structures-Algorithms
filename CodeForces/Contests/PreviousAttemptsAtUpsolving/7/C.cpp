#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
#define ff first
#define ss second
#define MP make_pair
#define nline endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(a,b,c)for(ll a=(b);a<(c);a++)
typedef long long ll;
typedef pair <int,int>pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
bool rev(int&a,int&b){return a>b;}
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

    int n,k,days;cin>>n>>k>>days;
    vector<int>arr(n),b(k);

    rep(i,0,n){
        cin>>arr[i];
    }

    rep(i,0,k){
        cin>>b[i];
    }

    ll ans=0;

    rep(i,0,min(2*n+1,days)){

        ll curr=0;

        rep(j,0,n){

            curr+=(arr[j]==j+1);

        }

        curr+=(days-i-1)/2;

        ans=max(ans,curr);

        rep(j,0,b[i%k]){
            arr[j]++;
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