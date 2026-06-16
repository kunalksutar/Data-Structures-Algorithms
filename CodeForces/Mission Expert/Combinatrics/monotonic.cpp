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

int n,m,k,a,b,c,d;

const int mod=998244353;

int calc(int n){
    int ans=1;
    int temp=2;

    while(n){

        if(n%2){//odd power

            ans=mod_mul(ans,temp,mod);
            n-=1;

        }else{//even power

            temp=mod_mul(temp,temp,mod);
            n/=2;

        }

    }

    return ans;
}

void solve(){
    cin>>n;
    vi arr(n);

    map<int,int>mp;//will store the last occurance of every element

    rep(i,0,n){

        cin>>arr[i];
        mp[arr[i]]=i;

    }

    int last_occ=mp[arr[0]];

    int groups=0;

    rep(i,0,n){

        if(last_occ==-1){

            last_occ=mp[arr[i]];

        }

        if(last_occ==i){

            groups++;
            last_occ=-1;
            continue;

        }
        
        last_occ=max(last_occ,mp[arr[i]]);

    }

    cout<<calc(groups-1)<<endl;

}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}