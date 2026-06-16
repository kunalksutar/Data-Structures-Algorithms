#include<bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
using namespace std;

int getMex(vector<int> &nums, int left, int right) {
    int n = nums.size();
    set<int> st;

    for (int i = 0; i <= n/2; i++) {
        st.insert(i);
    }

    while (left >= 0 && right < n && nums[left] == nums[right]) {
        st.erase(nums[left]);

        left--;
        right++;
    }

    return *st.begin();
}

void solve(){
    int n; cin >> n;
    vector<int> nums(2*n), next(2*n, -1);
    // next[i] => next idx with same nums[i]
    int x = -1, y = -1; 

    for (int i = 0; i < 2*n; i++) {
        cin >> nums[i];

        if (nums[i] == 0) {
            if (x == -1) {
                x = i;
            } else {
                y = i;
            }
        }
    }

    cout << max({getMex(nums, x, x),
        getMex(nums, y, y),
        getMex(nums, (x+y)/2, (x+y+1)/2)}) << endl;    
}

int main(){
    int t; cin >> t;
    //t=1;
    while(t--) solve();
    return 0;
}