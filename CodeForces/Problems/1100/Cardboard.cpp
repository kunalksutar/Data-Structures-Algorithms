#include <cstdlib>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <list>
#include <deque>
#include <array>
#include <cassert>
#include <algorithm>
#include <string>
#define all(x) x.begin(),x.end()
using namespace std;

void solve(){
    int n;cin>>n;//number of paintings.
        long long c;cin>>c;//total area of cardboard used.
        vector<int>s(n);
        for(int i=0;i<n;i++)cin>>s[i];
        
        long long left=0,right=1000000000;
        while(right>=left){
            long long mid=(left+right+1)/2;
            long long sumAll=0;
            for(int i=0;i<n;i++){
                sumAll+=(s[i]+(2*mid))*(s[i]+(2*mid));
                if(sumAll>c)break;
            }
            if(sumAll==c){
                cout<<mid<<endl;
                return;
            }else if(sumAll>c)right=mid-1;
            else left=mid+1;
        }
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}