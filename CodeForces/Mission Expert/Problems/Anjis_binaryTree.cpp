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

ll DFS(ll curr_node,vpll&adj,string&s){
    ll left_node=adj[curr_node].ff;
    ll right_node=adj[curr_node].ss;

    if(curr_node==-1){
        return 1e9;
    }else if(left_node==right_node && left_node==-1){//if leaf node
        return 0;
    }

    ll ans=1e9;

    if(s[curr_node]=='L'){//if left 

        ans=min(ans,  DFS(left_node,adj,s));//decide to go left
        ans=min(ans,1+DFS(right_node,adj,s));//decide to go right

    }else if(s[curr_node]=='R'){//if Right    

        ans=min(ans,1+DFS(left_node,adj,s));//decide to go left
        ans=min(ans,  DFS(right_node,adj,s));//decide to go right

    }else{//if up

        ans=min(ans,1+DFS(left_node,adj,s));//decide to go left
        ans=min(ans,1+DFS(right_node,adj,s));//decide to go right

    }

    return ans;

}

void solve(){
    cin>>n;
    string s;cin>>s;
    vpll adj(n);

    rep(i,0,n){
        cin>>a>>b;
        a--;b--;

        adj[i].ff=a;
        adj[i].ss=b;
    }

    cout<<DFS(0,adj,s)<<endl;

}

int main(){
int t=1;
cin>>t;
while(t--)solve();
return 0;
}