#include<bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    ll n, k; cin >> n >> k;
    ll total = 0;

    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        total += a;
    }

    if (total%2 || (n*k)%2==0) {
        // total is odd or 
        // can be made even so that 
        // first player is the last person 
        // to end it 
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}