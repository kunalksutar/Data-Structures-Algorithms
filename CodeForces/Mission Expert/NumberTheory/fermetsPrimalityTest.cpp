#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

ll mulmod(ll a,ll b,ll mod){
    //whole point of this function is to mulitply 2 long long numbers
    //without throwing the integer overflow error.
    ll ans=0,temp=a%mod;
    while(b){
        if(b%2)ans=(ans+temp)%mod;
        temp=((2ll*temp))%mod;
        b/=2;
    }return ans%mod;
}

ll binmod(ll base,ll power,ll mod){
    ll ans=1;
    while(power){
        if(power%2){//odd power
            power--;
            ans=mulmod(ans,base,mod);
        }else{
            power/=2;
            base=mulmod(base,base,mod);
        }
    }return ans;
}

bool isPrime(ll n,int iter){
    if(n<4)return n==2||n==3;

    for(int i=0;i<iter;i++){
        //first randomly selecting a number 
        //between 2 and n-3
        //since the rand()%(n-3) can at max give a value of n-4
        ll a=2+rand()%(n-3);

        ll ans=binmod(a,n-1,n);
        if(ans!=1)return false;
    }return true;
}

void solve(){
    int q;cin>>q;
    while(q--){
        ll n;cin>>n;

        if(isPrime(n,5))cout<<"YES"<<endl;    
        else cout<<"NO"<<endl;
    }
}

int main(){
int t;//cin>>t;
t=1;
while(t--)solve();
return 0;
}