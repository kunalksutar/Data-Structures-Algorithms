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

void generate_next_mask(ll curr_mask,ll next_mask,ll index,ll&n,vector<ll>&next_masks){
    if(index==n){
        next_masks.push_back(next_mask);
        return;
    }

    //bit masking will be done from index=1 to index=n

    if((curr_mask&(1<<index))!=0){//if 1 => we can not fit anything here
        generate_next_mask(curr_mask,next_mask,index+1,n,next_masks);
    }

    if((curr_mask&(1<<index))==0){//if 0 => we can place one peice horizontal here
        generate_next_mask(curr_mask,next_mask+(1<<index),index+1,n,next_masks);
    }

    if(index+1<n && ((curr_mask&(1<<index))==0) && ((curr_mask&(1<<(index+1)))==0)){//if both are 0=> 
        //then we can simply place one vertical and that is it 
        generate_next_mask(curr_mask,next_mask,index+2,n,next_masks);
    }   
}

ll dfs(ll index,ll mask,ll&n,ll&m,vector<vector<ll>>&dp){
    if(index==m){
        return mask==0;
    }else if(dp[index][mask]!=-1){
        return dp[index][mask];
    }

    vector<ll>next_masks;
    generate_next_mask(mask,0,0,n,next_masks);

    ll ans=0;
    //cout<<"index:"<<index<<endl;

    for(int i=0;i<next_masks.size();i++){
        //cout<<next_masks[i]<<endl;
        ans=(ans+dfs(index+1,next_masks[i],n,m,dp))%MOD;
    }

    //cout<<endl;
    return dp[index][mask]=ans;
}

void solve(){
    ll n,m;cin>>n>>m;

    vector<vector<ll>>dp(m,vector<ll>((1<<n),-1));
    cout<<dfs(0,0,n,m,dp)<<endl;
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}