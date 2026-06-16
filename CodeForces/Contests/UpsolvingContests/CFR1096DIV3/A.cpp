#include<bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    int x, y; cin >> x >> y;

    if (x%2 && y%2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}