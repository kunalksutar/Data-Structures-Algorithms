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
    ll n,x;cin>>n>>x;
    vector<ll>arr(n);
 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
 
    vector<pair<ll,ll>>dp(1<<n);
    dp[0]={1,0};
    //number of container, space taken

    for(int mask=1;mask<(1<<n);mask++){
        pair<ll,ll>temp={1e9,1e9};
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                pair<ll,ll>curr=dp[mask^(1<<i)];
                
                if(curr.second+arr[i]>x){
                    curr.first++;
                    curr.second=arr[i];
                }else{
                    curr.second+=arr[i];
                }

                temp=min(temp,curr);
            }
        }

        dp[mask]=temp;
    }

    cout<<dp[(1<<n)-1].first<<endl;
}
 
int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}