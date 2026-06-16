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

int f(vector<vector<char>>&board,int idx,vector<int>&d_sum,
    vector<int>&d_diff,vector<int>&horr){
    if(idx==8){
        return 1;
    }

    int ans=0;
    for(int i=0;i<8;i++){
        int x=i;
        int y=idx;

        if(!d_sum[x+y] && !d_diff[x-y+7] && !horr[x] && board[x][y]!='*'){
            d_sum[x+y]=1;
            d_diff[x-y+7]=1;
            horr[x]=1;

            ans+=f(board,idx+1,d_sum,d_diff,horr);

            d_sum[x+y]=0;
            d_diff[x-y+7]=0;
            horr[x]=0;
        }
    }

    return ans;
}

void solve(){
    vector<vector<char>>board(8,vector<char>(8));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>board[i][j];
        }
    }

    int ans=0;
    vector<int>d_sum(15,0),d_diff(15,0),horr(8,0);
    cout<<f(board,0,d_sum,d_diff,horr)<<endl;
    
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}