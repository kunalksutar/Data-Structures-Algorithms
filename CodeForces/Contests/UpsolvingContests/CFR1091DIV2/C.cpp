#include<bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    ll n, m, a, b; 
    cin >> n >> m >> a >> b;

    bool possible = (
        __gcd(n, a) == 1 &&
        __gcd(m, b) == 1 && 
        __gcd(n, m) <= 2
    );

    if (possible) {
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