#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/detail/standard_policies.hpp>
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

template<class T>
using minHeap=priority_queue<T,vector<T>,greater<T>>;

int n,m,k,a,b,c,d;

void solve(){
    cin>>n>>m;

    vector<vpll>adj(n+1);

    vll s(n+1);

    rep(i,0,m){
        ll u,v,w;

        cin>>u>>v>>w;

        adj[u].pb(MP(v,w));
        adj[v].pb(MP(u,w));

    }

    rep(i,1,n+1){
        cin>>s[i];
    }

    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;

    pq.push(MP(0,MP(1,s[1])));

    vector<vll> DIST(n+1,vll(1005,INT64_MAX));

    while(!pq.empty()){
        ll curr_dist=pq.top().ff;
        ll node=pq.top().ss.ff;
        ll slowness=pq.top().ss.ss;

        pq.pop();

        if(curr_dist<DIST[node][slowness]){
            DIST[node][slowness]=curr_dist;

            rep(i,0,adj[node].size()){
                ll adj_node=adj[node][i].ff;
                ll adj_w=adj[node][i].ss;
                ll adj_slowness=min(s[node],slowness);

                ll new_dist=curr_dist+(adj_slowness*adj_w);

                pq.push(MP(new_dist,MP(adj_node,adj_slowness)));
            }
        }
    }

    ll ans=INT64_MAX;

    rep(i,1,1001){
        ans=min(ans,DIST[n][i]);
    }

    cout<<ans<<endl;
}

int main(){
int t=1;
cin>>t;
while(t--)solve();
return 0;
}