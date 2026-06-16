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

class DisjointSet{
    private:
        vector<int>rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findParent(int u){
            if(parent[u]==u){
                return u;
            }

            return parent[u]=findParent(parent[u]);
        }

        void unionByRank(int u,int v){
            int parent_u=findParent(u);
            int parent_v=findParent(v);

            if(parent_u!=parent_v){
                if(rank[parent_u]<rank[parent_v]){
                    parent[parent_u]=parent_v;
                }else if(rank[parent_u]>rank[parent_v]){
                    parent[parent_v]=parent_u;
                }else{
                    parent[parent_v]=parent_u;
                    rank[parent_u]++;
                }
            }
        }
};

bool safe(int r,int c,int n,int m){
    return r>=0 && c>=0 && r<n && c<m;
}

void solve(){
    vector<vector<int,int>>Q;
    int q=Q.size();
    int n,m;

    vector<vector<int>>dp(n,vector<int>(m,0));  
    int col=1;

    vector<int>delr={0,0,1,-1};
    vector<int>delc={1,-1,0,0};

    DisjointSet ds(n);

    for(int i=0;i<q;i++){
        int r=Q[i][0];
        int c=Q[i][1];

        for(int j=0;j<4;j++){
            int nr=r+delr[j];
            int nc=c+delc[j];

            if(safe(nr,nc,n,m) && ){

            }
        }
    }
}

int main(){
int t=1;
cin>>t;
while(t--)solve();
return 0;
}