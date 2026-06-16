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

priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

// HOW TO MAKE THE PBDS LIBRARY WORK
// Inside the following folder : C:\MinGW\lib\gcc\mingw32\6.3.0\include\c++\ext\pb_ds\detail\resize_policy
// Rename the name of the folder by removing the remaining numbers at the very end hash_standard_resize_policy_imp.hpp

static bool compare(vector<ll>&a,vector<ll>&b){
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
    vector<ll>contained(n,0),contains(n,0);
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;

        arr.push_back({x,y,i});
    }

    sort(all(arr),compare);

    ordered_set<pair<ll,ll>>st;
    for(int i=0;i<n;i++){
        ll curr_start=arr[i][0];
        ll curr_end=arr[i][1];
        ll index=arr[i][2];

        st.insert({curr_end,-i});

        contained[index]=st.size()-st.order_of_key({curr_end,-i})-1;
    }   

    st.clear();

    for(int i=n-1;i>=0;i--){
        ll curr_start=arr[i][0];
        ll curr_end=arr[i][1];
        ll index=arr[i][2];

        st.insert({curr_end,-i});

        contains[index]=st.order_of_key({curr_end,-i});
    }

    for(int i=0;i<n;i++){
        cout<<contains[i]<<" ";
    }

    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<contained[i]<<" ";
    }
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}