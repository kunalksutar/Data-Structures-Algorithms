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
bool rev(ll&a,ll&b){return a>b;}
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

    if(n%2){//if odd number of players;
    //it is very clear we will win n-1/2 
    //and loss n-1/2

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(j-i<=n/2){
                    cout<<1<<" ";
                }else{
                    cout<<-1<<" ";
                }
            }
        }

    }else{
        //now will have to squeeze in another
        //draw in there
        //we will break it at exactly middle.

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(j-i<n/2){
                    cout<<1<<" ";
                }else if(j-i==n/2){
                    cout<<0<<" ";
                }else{
                    cout<<-1<<" ";
                }
            }
        }
    }

    cout<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}