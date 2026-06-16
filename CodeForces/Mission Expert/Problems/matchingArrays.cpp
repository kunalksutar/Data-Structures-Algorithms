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

int n,m,k,a_,b,c,d;

void solve(){
    cin>>n>>k;
    vi b(n),a_copy(n);
    vpii a(n);

    rep(i,0,n){
        cin>>a[i].ff;
        a_copy[i]=a[i].ff;
        a[i].ss=i;
    }

    rep(i,0,n){
        cin>>b[i];
    }

    sort(all(a));
    sort(all(b));

    vi ans(n);

    rep(i,0,k){
        ans[a[n-i-1].ss]=b[i];
    }

    rep(i,k,n){
        ans[a[i-k].ss]=b[i];
    }

    rep(i,0,n){
        if(a_copy[i]>ans[i])k--;
    }

    if(k!=0){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;

    rep(i,0,n){
        cout<<ans[i]<<" ";
    }

    cout<<endl;

}

int main(){
int t=1;
cin>>t;
while(t--)solve();
return 0;
}