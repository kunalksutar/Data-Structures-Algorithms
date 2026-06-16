#include<cstdlib>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    vector<long long> nums(n), prefix(n+1, 0);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + nums[i-1];
    }

    vector<long long> res;

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--; r--;

        res.push_back(prefix[r+1]-prefix[l]);
    }

    for (int i = 0; i < q; i++) {
        cout << res[i] << endl;
    }

    return 0;
}
