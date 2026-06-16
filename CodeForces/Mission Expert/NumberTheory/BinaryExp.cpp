#include<bits/stdc++.h>
#define MP make_pair
#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

int recurr(int base,int power){
    if(power==0)return 1;

    if(power%2){//odd power
        return base*recurr(base,power-1);
    }return recurr(base*base,power/2);
}

void solve(){
    int a,x,ans=1;cin>>a>>x;

    cout<<recurr(a,x)<<endl;

    while(x){
        if(x%2){//odd power
            ans*=a;
            x--;
        }else{//even power
            a*=a;
            x/=2;
        }
    }
}

int main(){
int t;//cin>>t;
t=1;cout<<(1<<0);
while(t--)solve();
return 0;
}