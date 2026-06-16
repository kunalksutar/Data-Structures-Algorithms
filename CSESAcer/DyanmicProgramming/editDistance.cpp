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

ll dfs(int index1,int index2,string&a,string&b,vector<vector<ll>>&dp){
    if(index1==a.size() && index2==b.size()){
        return 0;
    }else if(index1==a.size()){
        return b.size()-index2;
    }else if(index2==b.size()){
        return a.size()-index1;
    }else if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }

    ll ans=0;

    if(a[index1]==b[index2]){
        ans=dfs(index1+1,index2+1,a,b,dp);
    }else{
        ans=1+min(dfs(index1+1,index2+1,a,b,dp),//make a force full match
                  min(dfs(index1,index2+1,a,b,dp),//del from b
                      dfs(index1+1,index2,a,b,dp)));//del from a
    }

    return dp[index1][index2]=ans;
}

void solve(){
    string a,b;cin>>a>>b;
    int n=a.size();
    int m=b.size();

    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }

    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){//if same
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=1ll+min(dp[i-1][j-1],
                             min(dp[i-1][j],
                                 dp[i][j-1]));
            }
        }
    }

    cout<<dp[n][m]<<endl;
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}