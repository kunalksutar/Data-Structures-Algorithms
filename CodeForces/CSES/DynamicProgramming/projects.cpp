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
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
#define rep(a,b,c)for(ll a=(b);a<(c);a++)
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

priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

static bool compare(vector<ll>&a,vector<ll>&b){
    if(a[1]==b[1]){
        return a[0]<b[0];
    }

    return a[1]<b[1];
}

void solve(){
    ll n;cin>>n;
    map<ll,ll>mp;
    //{end,tot_price}
    vector<vector<ll>>arr(n,vector<ll>(3));
    
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }

    sort(all(arr),compare);

    ll maxx=0;
    for(int i=0;i<n;i++){
        ll start=arr[i][0];
        ll end=arr[i][1];
        ll price=arr[i][2];

        auto it=mp.lower_bound(start);

        if(it==mp.begin()){
            maxx=max(maxx,price);
        }else{
            it--;
            ll tot_price=it->second;
            maxx=max(maxx,price+tot_price);
        }

        mp[end]=max(mp[end],maxx);
    }

    cout<<maxx<<endl;
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}