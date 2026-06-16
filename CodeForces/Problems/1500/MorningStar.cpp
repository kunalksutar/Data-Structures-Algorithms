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

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        map<int,long long>sameX,sameY,sameDiff,sameAdd;

        for(int i=0;i<n;i++){
            int x,y;cin>>x>>y;
            sameX[y]++;sameY[x]++;sameDiff[x-y]++;sameAdd[x+y]++;
        }

        long long ans=0;
        for(auto &a:sameX){
            ans+=a.second*(a.second-1);
        }
        for(auto &a:sameY){
            ans+=a.second*(a.second-1);
        }
        for(auto &a:sameDiff){
            ans+=a.second*(a.second-1);
        }
        for(auto &a:sameAdd){
            ans+=a.second*(a.second-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}