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

void solve(){
    ll n;cin>>n;
    ll sum=(n*(n+1))/2;
    string ans="NO";
    vi v1,v2;

    //cout<<"sum:"<<sum<<endl;

    if(sum%2==0){
        if(n%4==0){
            for(int i=1;i<=n;i++){
                if(i<=n/4 || i>3*(n/4)){
                    v1.pb(i);
                }else{
                    v2.pb(i);
                }
            }

            ans="YES";
        }else if(n%4==3){
            v1.pb(1);
            v1.pb(2);
            v2.pb(3);
            n-=3;
            for(int i=1;i<=n;i++){
                if(i<=n/4 || i>3*(n/4)){
                    v1.pb(i+3);
                }else{
                    v2.pb(i+3);
                }
            }
            
            ans="YES";
        }
    }

    cout<<ans<<endl;

    if(ans=="YES"){
        cout<<v1.size()<<endl;
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }

        cout<<endl;

        cout<<v2.size()<<endl;
        for(int i=0;i<v2.size();i++){
            cout<<v2[i]<<" ";
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