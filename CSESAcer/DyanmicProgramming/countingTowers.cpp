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

int N=1e6;
vector<vector<ll>>dp(N+1,vector<ll>(8,0));

void solve(){
    //instead of making focusing on the blocks,
    //we focus on the points at center at each step
    //they will always have a unique finger print for each combo
    //and there are 8 such unique prints for those centers

    for(int combo=0;combo<8;combo++){
        dp[0][combo]=1;
    }

    for(int i=1;i<N;i++){
        for(int combo=0;combo<8;combo++){
            if(combo==0||combo==2||combo==3||combo==4||combo==5){
                dp[i][combo]=(
                     dp[i-1][0]%MOD
                    +dp[i-1][1]%MOD
                    +dp[i-1][3]%MOD
                    +dp[i-1][4]%MOD
                    +dp[i-1][5]%MOD
                )%MOD;
            }else{
                dp[i][combo]=(
                     dp[i-1][2]%MOD
                    +dp[i-1][6]%MOD
                    +dp[i-1][7]%MOD
                )%MOD;
            }
        }
    }
}

int main(){
int t=1;
cin>>t;
solve();
while(t--){
    ll n;cin>>n;
    cout<<(dp[n-1][3]+dp[n-1][7])%MOD<<endl;
    //we only add these 2 specific combos since those are the only 
    //ones that will be eligible to be the top most center point
    //draw and think about it
}
return 0;
}