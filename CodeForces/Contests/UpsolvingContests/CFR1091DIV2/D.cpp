#include<bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    // input section 
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> p;

    for (int i = 0; i < k; i++) {
        ll idx; cin >> idx;
        idx--; // converting to 0 based indexing 
        p.push_back(idx);
    }

    ll bit = a[p[0]];

    // to handle the right edge case 
    if (p[p.size()-1] != n-1) {
        // if last index is not a pivot index
        p.push_back(n); // adding the last index 
        a.push_back(bit); // adding the target bit 
        n++; 
    }

    // traverse from left to right 

    ll pz = p.size();
    ll res = 0;
    ll prevLeft = 0;

    for (int i = 0; i < pz; i++) {
        ll left = 0;
        ll leftLimit = -1;
        bool flag = false;

        if (i) {
            leftLimit = p[i-1];
        }

        for (int j = p[i]; j > leftLimit; j--) {
            if (flag) {
                flag = false;
                left += 2;
            } else if (a[j] != a[p[i]]) {
                flag = true;
            }
        }

        if (flag) {
            // handle edge case 
            left += 2;
        }

        // update res 
        res += max(0LL, left-prevLeft);

        // update for the next iteration 
        prevLeft = left;
    }

    cout << res << endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}