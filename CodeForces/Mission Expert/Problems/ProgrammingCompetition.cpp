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

void solve(){
    cin>>n;

    vector<vi>adj(n+1);

    rep(i,2,n+1){

        int x;cin>>x;
        adj[x].pb(i);

    }

    queue<int>Q;

    Q.push(1);

    int remainder;
    ll ans;

    int f=1;


    while(!Q.empty()){
        int len=Q.size();

        if(f){
            ans=0;
            remainder=0;

            f=0;
        }else{

            

        }

        rep(i,0,len){
            int curr_node=Q.front();
            Q.pop();

            rep(j,0,adj[curr_node].size()){
                int adj_node=adj[curr_node][j];

                Q.push(adj_node);
            }

        }

    }

    cout<<ans<<endl;
}

int main(){
int t=1;
cin>>t;
while(t--)solve();
return 0;
}