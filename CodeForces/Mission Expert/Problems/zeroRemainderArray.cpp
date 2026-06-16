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
    int n,k;cin>>n>>k;
    
    ll ans=0;
    map<int,int>cnt;
    int maxx=INT32_MIN;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        
        if(x%k){//because we don't want to consider 
        //any divisible cases, we will not think about 
        //them at all
            maxx=max(maxx,++cnt[k-x%k]);
        }
    }

    for(auto it:cnt){
        if(it.second==maxx){
            ans=(ll)k*(maxx-1)+it.first+1;
            //k*(maxx-1) the number of cycles that we will 
            //have to make

            //+(key+1) to reach to the first destination and keep 
            //cycling from there
        }
    }

    cout<<ans<<nline;
}

int main(){
int t;cin>>t;//t=1;
while(t--)solve();
return 0;
}