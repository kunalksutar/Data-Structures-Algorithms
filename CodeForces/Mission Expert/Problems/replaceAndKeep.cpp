#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

void solve(){
    int n,q,k;cin>>n>>q>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    while(q--){
        int l,r;cin>>l>>r;

        cout<<k+arr[r-1]-arr[l-1]-2*(r-l)-1<<endl;
    }
}

int main(){
int t;t=1;
while(t--)solve();
return 0;
}