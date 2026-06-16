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

bool bs(ll&score,vector<ll>&arr,ll&k){
    ll cuts=0;
    ll sum=0;

    for(int i=0;i<arr.size();i++){
        if(sum+arr[i]>score){
            cuts++;
            sum=arr[i];
        }else{
            sum+=arr[i];
        }

        if(arr[i]>score){
            return false;
        }

        if(cuts==k){
            return false;
        }
    }

    return true;
}

void solve(){
    ll n,k;cin>>n>>k;
    vector<ll>arr(n);
    ll right=0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        right+=arr[i];
    }

    ll left=0;
    ll ans=0;

    while(left<=right){
        ll mid=left+(right-left)/2;

        if(bs(mid,arr,k)){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }

    cout<<ans<<endl;
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}