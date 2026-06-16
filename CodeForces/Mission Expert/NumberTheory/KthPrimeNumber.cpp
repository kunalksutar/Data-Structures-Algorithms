#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

void solve(){
    int q;cin>>q;
    vector<int>arr(q);
    for(int i=0;i<q;i++)cin>>arr[i];

    int maxx=90*1e6;
    //this will only be solve by seive method.
    vector<bool>isPrime(maxx+1,true);//initially marking 
    //all elements as prime number
    isPrime[0]=isPrime[1]=false;

    for(int i=2;i*i<=maxx;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=maxx;j+=i){
                isPrime[j]=false;
            }
        }
    }

    vector<int>primes;
    for(int i=2;i<=maxx;i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }

    for(int i=0;i<q;i++){
        cout<<primes[arr[i]-1]<<endl;
    }return;
}

int main(){
int t;//cin>>t;
t=1;
while(t--)solve();
return 0;
}