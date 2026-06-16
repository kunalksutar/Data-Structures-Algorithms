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

int n,m,k,a,b,c,d;

void dfs(int node,int parent_node,
map<int,int>&dist,vector<vector<int>>&adj){
    for(int i=0;i<adj[node].size();i++){
        int adj_node=adj[node][i];
        if(adj_node!=parent_node){
            dist[adj_node]=dist[node]+1;
            dfs(adj_node,node,dist,adj);
        }
    }
}

int count_ways(int l,int r,int n){
    return (long long)pow(2,r-l-1)%MOD;
}

void solve(){
    int n;
    cin>>n;
    int edge_node;

    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        if(adj[u].size()==1){
            edge_node=u;
        }

        if(adj[v].size()==1){
            edge_node=v;
        }
    }

    map<int,int>dist;
    dist[edge_node]=0;

    dfs(edge_node,-1,dist,adj);

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;

        cout<<count_ways(l,r,n)<<endl;
    }
}

int main(){
int t=1;
cin>>t;
while(t--)solve();
return 0;
}