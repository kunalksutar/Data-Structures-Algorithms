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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
static bool compare1(vector<ll>&a,vector<ll>&b){
    if(a[0]==b[0]){
        return a[1]>b[1];//this will make sure to
        //keep the closing brackets in front in case
        //of a conflict
    }

    return a[0]<b[0];
}

void solve(){
    ll n;cin>>n;

    vector<vector<ll>>arr;
    for(int i=0;i<n;i++){
        ll a,b;cin>>a>>b;

        arr.push_back({a, 1,i});
        arr.push_back({b,-1,i});
    }

    sort(all(arr),compare1);

    vector<ll>rooms(n,0);
    
    ll mx=0;
    ll curr=0;
    vector<ll>emptyRooms;

    for(int i=0;i<2*n;i++){
        ll type=arr[i][1];
        ll index=arr[i][2];

        if(type==1){//arrival
            curr++;
            if(emptyRooms.size()){//if empty rooms are available
                rooms[index]=emptyRooms.back();
                emptyRooms.pop_back();
            }else{
                rooms[index]=curr;
            }
        }else{//departure
            curr--;
            emptyRooms.push_back(rooms[index]);
        }

        mx=max(mx,curr);
    }

    cout<<mx<<endl;
    for(int i=0;i<n;i++){
        cout<<rooms[i]<<" ";
    }
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}