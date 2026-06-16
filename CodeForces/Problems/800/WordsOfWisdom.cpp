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
        int winner,maxQuality=INT32_MIN;
        for(int i=1;i<=n;i++){
            int x,y;cin>>x>>y;
            if(maxQuality<y && x<11){
                winner=i;
                maxQuality=y;
            }
        }

        cout<<(n==1?1:winner)<<endl;
    }
    return 0;
}