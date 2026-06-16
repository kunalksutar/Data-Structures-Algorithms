#include<bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> res, twos, threes, nones;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;

        if (num%2 == 0 && num%3 == 0) {
            // pushing straight to result
            res.push_back(num);
        } else if (num%2 == 0) {
            twos.push_back(num);
        } else if (num%3 == 0) {
            threes.push_back(num); 
        }  else {
            nones.push_back(num);
        }
    }

    if (threes.size() > twos.size()) {
        for (int i = 0; i < twos.size(); i++) {
            res.push_back(twos[i]);
        }

        for (int i = 0; i < nones.size(); i++) {
            res.push_back(nones[i]);
        }

        for (int i = 0; i < threes.size(); i++) {
            res.push_back(threes[i]);
        }
    } else {
        for (int i = 0; i < threes.size(); i++) {
            res.push_back(threes[i]);
        }

        for (int i = 0; i < nones.size(); i++) {
            res.push_back(nones[i]);
        }

        for (int i = 0; i < twos.size(); i++) {
            res.push_back(twos[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }

    cout << endl;
}

int main(){
    int t; cin >> t;
    //t=1;
    while(t--) solve();
    return 0;
}