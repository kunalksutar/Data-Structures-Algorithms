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

bool safe(ll&x,ll&y,ll&n){
    return x>=0 && y>=0 && x<n && y<n;
}

void solve(){
    ll n;cin>>n;
    vector<vector<ll>>dist(n,vector<ll>(n,INT32_MAX));
    deque<pair<ll,pair<ll,ll>>>dq;
    vector<ll>x_dir={2, 2,1, 1,-1,-1,-2,-2};
    vector<ll>y_dir={1,-1,2,-2, 2,-2,-1, 1};
    dist[0][0]=0;
    dq.push_back({0ll,{0ll,0ll}});

    while(dq.size()){
        ll dis=dq.front().first;
        ll x=dq.front().second.first;
        ll y=dq.front().second.second;
        dq.pop_front();
        
        for(int i=0;i<8;i++){
            ll nx=x+x_dir[i];
            ll ny=y+y_dir[i];

            if(safe(nx,ny,n) && dis+1<dist[nx][ny]){
                dist[nx][ny]=dis+1;
                dq.push_back({dis+1,{nx,ny}});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dist[i][j]<<" ";
        }

        cout<<endl;
    }
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}

