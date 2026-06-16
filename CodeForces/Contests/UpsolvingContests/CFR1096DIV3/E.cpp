#include<bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve() { 
    int n; cin >> n;
    vector<int> nums(n);
    long long totalBlocks = 0;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        totalBlocks += nums[i];
    }

    long long fixed = 0;

    vector<int> sufix(n);
    sufix[n-1] = nums[n-1];
    fixed += sufix[n-1];

    for (int i = n-2; i >= 0; i--) {
        sufix[i] = min(sufix[i+1], nums[i]);
        fixed += sufix[i];
    }

    long long movable = totalBlocks-fixed;
    long long curr = 1; 
    long long maxx = 1;

    for (int i = 0; i+1 < n; i++) {
        if (sufix[i] == sufix[i+1]) {
            curr++; 
        } else {
            maxx = max(maxx, curr);
            curr = 1;
        }
    }

    maxx = max(maxx, curr);

    cout << movable + maxx - 1 << endl;
}

int main(){
    int t; cin >> t;
    //t=1;
    while(t--) solve();
    return 0;
}