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

string s;
vector<vector<bool>>vis(7,vector<bool>(7,false));
ll ans;
const string moves="LRDU";
const vector<pair<int,int>>dirs={
    {0,-1},
    {0, 1},
    {1, 0},
    {-1,0}
};

const vector<pair<int,int>>eight_dirs={
    {-1,-1},
    {-1, 0},
    {-1, 1},
    { 0, 1},
    { 1, 1},
    { 1, 0},
    { 1,-1},
    { 0,-1}
};

bool isInside(int x,int y){
    return min(x,y)>=0 && max(x,y)<7;
}
bool isEmpty(int x,int y){
    return isInside(x,y) && !vis[x][y];
}

void dfs(int index,int x,int y){
    if(x==6 && y==0){
        if(index==48){
            ans++;
        }

        return;
    }
    
    //checking if there are any closed loops
    if(isEmpty(x,y-1) && isEmpty(x,y+1) && !isEmpty(x+1,y) && !isEmpty(x-1,y)){
        return;
    }

    if(!isEmpty(x,y-1) && !isEmpty(x,y+1) && isEmpty(x+1,y) && isEmpty(x-1,y)){
        return;
    }

    //checking if there are any chessboard like pattern then we will simply return 
    if(x>=1 && y>=1 && !isEmpty(x-1,y-1) && isEmpty(x-1,y) && isEmpty(x,y-1)){
        return;
    }

    if(x>=1 && y<=5 && !isEmpty(x-1,y+1) && isEmpty(x-1,y) && isEmpty(x,y+1)){
        return;
    }

    if(x<=5 && y<=5 && !isEmpty(x+1,y+1) && isEmpty(x+1,y) && isEmpty(x,y+1)){
        return;
    }

    if(x<=5 && y>=1 && !isEmpty(x+1,y-1) && isEmpty(x+1,y) && isEmpty(x,y-1)){
        return;
    }


    for(int i=0;i<4;i++){
        if(s[index]!='?' && moves[i]!=s[index]){
            continue;
        }else{
            const pair<int,int>dir=dirs[i];
            int nx=x+dir.first;
            int ny=y+dir.second;

            if(isEmpty(nx,ny)){
                vis[nx][ny]=true;
                dfs(index+1,nx,ny);
                vis[nx][ny]=false;
            }
        }
    }
}

void solve(){
    cin>>s;
    vis[0][0]=true;
    ans=0;
    dfs(0,0,0);
    cout<<ans<<endl;
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}