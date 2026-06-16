#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<long long> seg;

    SegmentTree(int n) {
        seg.assign(4*n+5, INT32_MAX);
    }

    void build(int idx, int left, int right, vector<long long> &nums) {
        // base case 
        if (left == right) {
            seg[idx] = nums[left];
            return;
        }

        int mid = left + (right-left)/2;

        // explore all branches 
        build(2*idx+1, left, mid, nums);
        build(2*idx+2, mid+1, right, nums);

        // execute at return time 
        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }

    long long query(int idx, int left, int right, int l, int r) {
        // 1. no overlap 
        if (left > r || right < l) {
            return INT32_MAX;
        }

        // 2. complete overlap 
        if (l <= left && right <= r) {
            return seg[idx];
        }

        // 3. partial overlap 
        int mid = left + (right-left)/2;

        long long lres = query(2*idx+1, left, mid, l, r);
        long long rres = query(2*idx+2, mid+1, right, l, r);

        return min(lres, rres);
    }
};

int main(){
    int n, q; cin >> n >> q;
    vector<long long> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    SegmentTree st(n);
    st.build(0, 0, n-1, nums);

    vector<long long> res(q);

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--; r--;

        res[i] = st.query(0, 0, n-1, l, r);
    }

    for (int i = 0; i < q; i++) {
        cout << res[i] << endl;
    }

    return 0;
}
