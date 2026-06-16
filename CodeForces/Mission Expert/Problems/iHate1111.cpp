#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    int x;cin>>x;
    for(int i=0;i<11;i++){
        //i will range from 0 to 10
        if(x>=i*111 && (x-(i*111))%11==0){
            cout<<"YES"<<endl;
            return;
        }
    }cout<<"NO"<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}