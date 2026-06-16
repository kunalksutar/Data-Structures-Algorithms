#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    int n;cin>>n;
    if(n==1){
        cout<<"NO"<<endl;
        return;
    }

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    return;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}