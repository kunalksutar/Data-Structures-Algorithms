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


void solve(){
    int n;cin>>n;
    string s;cin>>s;

    set<int>st;

    ll ans=0;

    //first we need to understand that if we carry out the second operation
    //any number of times and then we do operation 1, it is same as carrying
    //the first type of operation any number of times,
    //so it would only make sense to focus 1st type of operations 
    //number of times and then take type 2 operations

    //next, if we find the first occrance of a letter, there will be n-i 
    //number of unique strings that will be formed from it

    for(int i=0;i<n;i++){
        
        if(st.find(s[i])==st.end()){
            
            ans+=n-i;
            st.insert(s[i]);

        }

    }

    cout<<ans<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}