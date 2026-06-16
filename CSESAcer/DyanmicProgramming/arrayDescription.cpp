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

ll dfs(ll index,ll&m,vector<ll>&arr,vector<vector<ll>>&dp){
    if(index==arr.size()){
        return 1;
    }else if(dp[index][arr[index-1]]!=-1){
        return dp[index][arr[index-1]];
    }

    ll ans=0;
    if(arr[index]==0){//needs to be changed
        ll prev_num=arr[index-1];

        for(int i=max(1ll,prev_num-1);i<=min(m,prev_num+1);i++){
            arr[index]=i;
            ans=(ans%MOD+dfs(index+1,m,arr,dp)%MOD)%MOD;
        }

        arr[index]=0;
    }else{//if can not be changed   
        if(abs(arr[index]-arr[index-1])<=1){//if eligible
            ans=dfs(index+1,m,arr,dp);
        }
    }

    return dp[index][arr[index-1]]=ans;
}

void solve(){
    ll n,m;cin>>n>>m;
    vector<ll>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<ll>>dp(n,vector<ll>(m+1,0));
    
    if(arr[0]!=0){
        dp[0][arr[0]]=1;
    }else{
        for(ll num=1;num<=m;num++){
            dp[0][num]=1;
        }
    }

    for(int i=1;i<n;i++){
        for(ll num=1;num<=m;num++){
            if(arr[i]==0||arr[i]==num){//can be changed
                for(int del=-1;del<=1;del++){
                    if(num+del>=1 && num+del<=m){
                        dp[i][num]=(dp[i][num]%MOD+dp[i-1][num+del]%MOD)%MOD;
                    }
                }
            }
        }
    }

    ll ans=0;
    for(int i=1;i<=m;i++){
        ans=(ans%MOD+dp[n-1][i]%MOD)%MOD;
    }

    cout<<ans<<endl;
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}