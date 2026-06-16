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

ll func(ll left,ll right,vector<ll>&arr,vector<vector<ll>>&dp){//will return the ansewer for player 1
    if(left==right){
        return arr[left];
    }else if(left+1==right){
        return max(arr[left],arr[right]);
    }else if(dp[left][right]!=-1){
        return dp[left][right];
    }

    ll ans=0;
    ans=max(arr[left]+min(func(left+2,right,arr,dp),
                          func(left+1,right-1,arr,dp)),
            arr[right]+min(func(left,right-2,arr,dp),
                           func(left+1,right-1,arr,dp)));
    
    return dp[left][right]=ans;
}

void solve(){
    ll n;cin>>n;
    vector<ll>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(n==1){
        cout<<arr[0]<<endl;
        return;
    }

    vector<vector<ll>>dp(n,vector<ll>(n,-1));
    
    for(int i=n-1;i>=0;i--){
        dp[i][i]=arr[i];
        if(i+1<n){
            dp[i][i+1]=max(arr[i],arr[i+1]);
        }
        for(int j=i+2;j<n;j++){
            if(i+2<n){
                dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),
                             arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
            }else if(i+1<n){
                dp[i][j]=max(arr[i]+dp[i+1][j-1],
                             arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
            }else{
                dp[i][j]=arr[j]+dp[i][j-2];
            }
        }
    }
    
    cout<<dp[0][n-1]<<endl;
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}