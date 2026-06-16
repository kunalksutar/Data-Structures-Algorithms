#include<bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll p; cin >> p;
    p--; // converting to 0 based indexing 

    ll right = 0;
    bool f = 0;

    for (int i = p; i < n; i++) {
        if (a[i] != a[p]) {
            f = true;
        }else if (f) {
            // if elements are same but f is 1
            f = false;
            right += 2;
        }
    }

    // edge case 
    if (f) {
        f = false;
        right += 2;
    }

    ll left = 0;

    for (int i = p; i >= 0; i--) {
        if (a[i] != a[p]) {
            f = true;
        }else if (f) {
            // if elements are same but f is 1
            f = false;
            left += 2;
        }
    }

    if (f) {
        left += 2;
    }

    cout << max(left, right) << endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}