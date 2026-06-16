#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

int const maxN=1e6;
int phi[maxN+1];

void initiate(){
    for(int i=0;i<=maxN;i++){
        phi[i]=i;
    }
    
    for(int i=2;i<=maxN;i++){
        if(phi[i]==i){//meaning that this number is prime.
            for(int j=i;j<=maxN;j+=i){
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
}

int get_cnt(int d,int n){
    return phi[n/d];
}

void solve(){
//will print out the gcd sum of q queries.
    int q;cin>>q;
    initiate();
    
    for(int i=0;i<q;i++){
        int n;cin>>n;
        int ans=0;

        for(int i=1;i*i<=n;i++){
            if(n%i==0){//if i is a divisor
                int d1=i;
                int d2=n/i;

                ans+=d1*get_cnt(d1,n);

                if(d1!=d2){
                    ans+=d2*get_cnt(d2,n);
                }
            }
        }cout<<ans<<endl;
    }
}

int main(){
int t;//cin>>t;
t=1;
while(t--)solve();
return 0;
}