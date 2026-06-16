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

void solve(){
    ll a,b;cin>>a>>b;
    vector<ll>ans;

    if(a==b){
        cout<<0<<endl;
        return;
    }

    ll lenA=0;
    ll lenB=0;

    for(int i=0;i<31;i++){
        if((1<<i)&a){
            lenA=i;
        }

        if((1<<i)&b){
            lenB=i;
        }
    }

    if(lenB>lenA){
        cout<<-1<<endl;
        return;
    }
    
    for(int i=0;i<31;i++){
        ll num=(1<<i);
        if(num<=a && ((num&a)==0)){
            ans.push_back(num);
            //a+=num;
        }
    }

    for(int i=0;i<31;i++){
        ll num=(1<<i);
        if(num<=a && ((num&b)==0)){
            ans.push_back(num);
        }
    }

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
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