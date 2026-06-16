#include<bits/stdc++.h>
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
#define ff first
#define ss second
#define MP make_pair
#define nline endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
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

const ll mod=998244353;

ll recurr(ll num,ll low,ll high,int&ans){
    if(low==high){

        

    }

    ll mid=(low+high)/2;

    ll left=recurr(2*num,low,mid,ans);
    ll right=recurr(2*num+1,mid+1,high,ans);
    
    ans=mod_add(ans,mod_mul(num,mod_mul(left,right,mod),mod),mod);

    return left+right;
}

void solve(){
    ll n;cin>>n;

    int ans=0;

    recurr(1,1,2*n-1,ans);

    cout<<ans<<endl;
}

int main(){
int t;cin>>t;//t=1;
while(t--)solve();
return 0;
}