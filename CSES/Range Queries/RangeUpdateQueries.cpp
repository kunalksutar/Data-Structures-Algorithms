#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class FenwickTree {
public:
    vector<long long> seg;
    long long n;

    // constructor 
    FenwickTree(int _n) {
        n = _n;
        seg.assign(n+1, 0);
    }

    void update(int idx, long long val) {
        while (idx <= n) {
            seg[idx] += val;
            idx += (idx & -idx);
        }
    }

    long long query(int idx) {
        long long res = 0;
        while (idx >= 1) {
            res += seg[idx];
            idx -= (idx & -idx);
        }

        return res; 
    }
};


int main(){
    long long n, q; cin >> n >> q;
    vector<long long> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // build the fenwick tree
    FenwickTree tree(n);

    tree.update(1, nums[0]);

    for (int i = 1; i < n; i++) {
        long long diff = nums[i]-nums[i-1];
        tree.update(i+1, diff);
    }

    for (int i = 0; i < q; i++) {
        long long type; cin >> type;

        if (type == 1) {
            // range update 
            long long l, r, val; cin >> l >> r >> val;  
            tree.update(l, val);
            tree.update(r+1, -val);
        } else {
            // get value 
            long long pos; cin >> pos;
            long long res = tree.query(pos);

            cout << res << endl;
        }
    }

    return 0;
}
