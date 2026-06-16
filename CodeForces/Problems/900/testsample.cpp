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

int getMask(int num){
    int ans=0;
    while(num){
        int digit=num%10;
        ans = ans | (1<<digit);
        num/=10;
    }

    return ans;
}

void solve(){
    vector<int>A;
    int n=A.size();

    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        int mask=getMask(A[i]);
        if(mp.find(mask)==mp.end()){
            mp[mask]=A[i];
        }else{
            mp[mask]=max(mp[mask],A[i]);
        }
    }

    int ans=-1;
    for(auto it1=mp.begin();it1!=mp.end();it1++){
        for(auto it2=it1;it2!=mp.end();it2++){
            if(!(it1->ff & it2->ff)){
                ans=max(ans,it1->ss+it2->ss);
            }
        }
    }

    cout<<ans<<endl;
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}