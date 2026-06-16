#include<bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    int n; cin >> n;
    int open = 0; 
    int close = 0;

    for (int i = 0; i < n; i++) {
        char ch; cin >> ch;
        if (ch == '(') {
            open++;
        } else {
            close++;
        }
    }

    if (open == close) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


int main(){
    int t;cin>>t;
    //t=1;
    while(t--)solve();
    return 0;
}