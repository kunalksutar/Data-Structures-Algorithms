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
    ll n;cin>>n;
    string s;cin>>s;

    if(n==1){
        cout<<0<<endl;
        return;
    }

    vector<ll>pre_a(n);//the number of swaps needed to
    //make to get all elements to gather with last 
    //element standing at ith index

    ll cnt_a=(s[0]=='a');
    pre_a[0]=0;

    for(int i=1;i<n;i++){
        if(s[i]=='a'){
            cnt_a++;
            pre_a[i]=pre_a[i-1];
        }else{
            pre_a[i]=pre_a[i-1]+cnt_a;
        }
    }

    vector<ll>pre_b(n);

    ll cnt_b=(s[0]=='b');
    pre_b[0]=0;

    for(int i=1;i<n;i++){
        if(s[i]=='b'){
            cnt_b++;
            pre_b[i]=pre_b[i-1];
        }else{
            pre_b[i]=pre_b[i-1]+cnt_b;
        }
    }

    vector<ll>suf_a(n);
    suf_a[n-1]=0;
    cnt_a=(s[n-1]=='a');

    for(int i=n-2;i>=0;i--){
        if(s[i]=='a'){
            cnt_a++;
            suf_a[i]=suf_a[i+1];
        }else{
            suf_a[i]=suf_a[i+1]+cnt_a;
        }
    }

    vector<ll>suf_b(n);
    suf_b[n-1]=0;
    cnt_b=(s[n-1]=='b');

    for(int i=n-2;i>=0;i--){
        if(s[i]=='b'){
            cnt_b++;
            suf_b[i]=suf_b[i+1];
        }else{
            suf_b[i]=suf_b[i+1]+cnt_b;
        }
    }

    ll ans=INT64_MAX;
    for(int i=0;i<n-1;i++){
        ans=min(ans,min(pre_a[i]+suf_a[i+1],pre_b[i]+suf_b[i+1]));
    }

    cout<<ans<<endl;
}
 
int main(){
int t=1;
cin>>t;
while(t--)solve();
return 0;
}
