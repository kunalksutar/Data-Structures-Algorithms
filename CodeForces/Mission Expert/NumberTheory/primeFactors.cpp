#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

void solve(){
    int n;cin>>n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int count=0;
            while(n%i==0){
                count++;
                n/=i;
            }

            cout<<i<<"^"<<count<<" ";
        }
    }
}

int main(){
int t;//cin>>t;
t=1;
while(t--)solve();
return 0;
}