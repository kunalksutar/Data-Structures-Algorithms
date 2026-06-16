#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    vector<long long> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> prefix(n+1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1]^nums[i-1];
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--; r--;

        cout << (prefix[r+1]^prefix[l]) << endl;
    }

    return 0;
}
