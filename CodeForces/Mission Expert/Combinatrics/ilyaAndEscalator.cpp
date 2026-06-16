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

int n,m,k,a,b,c,d,t;

void solve(){

    cin>>n;
    ld p;cin>>p;
    cin>>t;

    vector<vector<ld>>dp(n+2,vector<ld>(t+2,0));

    dp[0][0]=1;//basecase

    rep(i,0,n+1){

        rep(j,0,t){

            if(i==n){//this is because we only want to mul the probablities
            //only n number of times and as we know the loop is running for 
            //n+1 number of times and to not include that we do this
            //we just simply carry the same number over to the next one 

            //now you must be wondering what about the dp[i+1][j+1] term.
            //but that is of no use since there can not be that many terms 
            //and even if we did, that is not going to change our answer.
                dp[i][j+1]+=dp[i][j];
              //dp[i+1][j+1]+=dp[i][j];
            }else{
                dp[i][j+1]+=(ld)(1-p)*dp[i][j];
                dp[i+1][j+1]+=(ld)p*dp[i][j];
            }

        }

    }

    ld ans=0;

    rep(i,0,n+1){

        ans+=(ld)dp[i][t]*i;

    }

    cout<<setprecision(10)<<ans<<endl;

}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}