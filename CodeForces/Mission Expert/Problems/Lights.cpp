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

ll n,m,k,a,b,c,d;

void toggle(int num,set<int>&st){
    if(st.find(num)!=st.end()){
        st.erase(num);
    }else{
        st.insert(num);
    }
}

bool recurr(int index,vi&arr,set<int>&st,vi&ans){
    if(index==arr.size()){
        return st.empty();
    }

    ans.pb(index+1);

    toggle(index+1,st);
    toggle(arr[index],st);

    bool res=recurr(index+1,arr,st,ans);

    if(!res){
        ans.ppb();

        toggle(index+1,st);
        toggle(arr[index],st);

        recurr(index+1,arr,st,ans);
    }
}

void solve(){
    cin>>n;

    string s;cin>>s;

    set<int>st;//will contain the indices of the bulbs that are turned on

    rep(i,0,n){
        if(s[i]=='1'){
            st.insert(i);
        }
    }

    vi arr(n);

    rep(i,0,n){
        cin>>arr[i];
        //arr[i]--;
    }

    vi ans;

    recurr(0,arr,st,ans);

    if(ans.size()){

        cout<<ans.size()<<endl;
        
        rep(i,0,ans.size()){
            cout<<ans[i]<<" ";
        }

        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    
}

int main(){
int t=1;
cin>>t;
while(t--)solve();
return 0;
}