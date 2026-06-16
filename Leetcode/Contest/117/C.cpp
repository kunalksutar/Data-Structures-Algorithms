#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

struct bitOr {
public: 
    vector<int>bits;

    // constructor 
    bitOr() {
        bits.resize(31, 0);
    }

    // will simply return the new OR 
    int getOr() {
        int res = 0;

        for(int i = 0; i < 31; i++){
            res += (1 << i) * (bits[i] > 0);
        }

        return res;
    }

    // will add the number to OR expression
    // and return the new OR 
    int addNum(int num) {
        for (int i = 0; i < 31; i++){
            bits[i] += num%2;
            num /= 2;
        }

        return getOr();            
    }        

    // remove number from the OR expression
    // and return the new OR expression 
    int removeNum(int num){
        for (int i = 0; i < 31; i++){
            bits[i] -= num%2;
            num /= 2;
        }

        return getOr(); 
    }
};

void solve(){
    vector<int> nums = {5,2,7};
    int n = nums.size();
        long long ans = 0;

        unordered_map<int, int> last;   // last occurrence of value
        vector<pair<int,int>> prev, cur; 
        // pair = {orValue, minimum start index for this OR group}

        for (int i = 0; i < n; i++) {
            last[nums[i]] = i;
            cur.clear();

            // subarray [i..i]
            cur.push_back({nums[i], i});

            // extend all previous subarrays ending at i-1
            for (auto &it : prev) {
                int val = it.first;
                int start = it.second;

                int nv = val | nums[i];
                if (cur.back().first == nv) {
                    cur.back().second = start;   // merge same OR group
                } else {
                    cur.push_back({nv, start});
                }
            }

            // Count good subarrays ending at i
            for (int k = 0; k < (int)cur.size(); k++) {
                int val = cur[k].first;
                int L = cur[k].second;
                int R = (k == 0 ? i : cur[k - 1].second - 1);

                if (last.count(val)) {
                    int p = last[val];
                    if (p >= L) {
                        ans += min(R, p) - L + 1;
                    }
                }
            }

            prev = cur;
        }

    cout<< ans;
}

int main(){
int t;//cin>>t;
t=1;
while(t--)solve();
return 0;
}