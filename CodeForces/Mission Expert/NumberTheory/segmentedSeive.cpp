#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

void solve(){
    int l,r;cin>>l>>r;
    //including the numbers from l to r.
    vector<bool>isPrime(r-l+1,true);//similar to sieve
    //we initally mark the numbers are prime

    for(int i=2;i*i<=r;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=r;j+=i){//this code can further be optimized by 
            //bring the j pointer directly just greater than l,
            //instead traversing the whole way through which is very inefficient.
            //later think about it
                if(j-l>=0){
                    isPrime[j-l]=false;
                }//answer should be 10 but is giving 15.
            }
        }
    }

    int ans=0;
    for(int i=0;i<=r-l;i++){
        if(isPrime[i])ans++;
    }cout<<ans<<endl;
}

int main(){
int t;//cin>>t;
t=1;
while(t--)solve();
return 0;
}