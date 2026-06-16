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
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a;
        cin>>a;
        int ans=abs(a-1);
        for(int i=2;i<=n;i++){
            int a;cin>>a;
            ans=__gcd(ans,abs(a-i));
        }
        cout<<ans<<endl;
    }
    return 0;
}