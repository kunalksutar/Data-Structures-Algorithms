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

ll recurr(int index,int f,vector<int>&arr,vector<vector<ll>>&dp){
    if(index==arr.size())return 0;
    else if(dp[index][f]!=-1)return dp[index][f];

    ll take,notTake;

    if(f){
        take=arr[index]+recurr(index+1,1-f,arr,dp);
    }else{
        take=-arr[index]+recurr(index+1,1-f,arr,dp);
    }

    notTake=recurr(index+1,f,arr,dp);

    return dp[index][f]=max(take,notTake);
}

void solve(){
    int n,q;cin>>n>>q;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<ll>>dp(n,vector<ll>(2,-1));

    cout<<recurr(0,1,arr,dp)<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}