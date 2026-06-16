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

int maxReach(int &x,int A[][4]){
    
}

void solve(){
    int n;cin>>n;
    int A[n][4];
    for(int i=0;i<n;i++)cin>>A[i][0]>>A[i][1]>>A[i][2]>>A[i][3];

    int q;cin>>q;
    int ans;
        for(int j=0;j<q;j++){
            int x;cin>>x;  
            ans=max(ans,maxReach(x,A));
        }
    cout<<ans<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}