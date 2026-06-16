#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<long long> seg;

    SegmentTree(int n) {
        seg.assign(4*n+5, 0);
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
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    long long query(int idx, int left, int right, int l, int r) {
        // 1. no overlap 
        if (left > r || right < l) {
            return 0;
        }

        // 2. complete overlap 
        if (l <= left && right <= r) {
            return seg[idx];
        }

        // 3. partial overlap 
        int mid = left + (right-left)/2;

        long long lres = query(2*idx+1, left, mid, l, r);
        long long rres = query(2*idx+2, mid+1, right, l, r);

        return lres+rres;
    }

    void update(int idx, int left, int right, int pos, int val) {
        // base case 
        if (left == right) {
            seg[idx] = val;
            return;
        } 

        int mid = left + (right-left)/2;

        if (pos <= mid) {
            update(2*idx+1, left, mid, pos, val);
        } else {
            update(2*idx+2, mid+1, right, pos, val);
        }

        // update at return time 
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
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

    vector<long long> res;

    for (int i = 0; i < q; i++) {
        int type; cin >> type;

        if (type == 1) {
            // update type 
            int pos, val; cin >> pos >> val;
            pos--;

            st.update(0, 0, n-1, pos, val);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;

            cout << st.query(0, 0, n-1, l, r) << endl;
        }
    }

    return 0;
}
