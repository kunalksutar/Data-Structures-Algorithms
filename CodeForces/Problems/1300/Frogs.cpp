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
        vector<int>jumps(n+1,0),counts(n+1,0);
        for(int i=1;i<=n;i++){
            int a;cin>>a;
            if(a<=n)jumps[a]++;//will show how many frogs have same jump length of 'a'.
        }

        for(int i=1;i<=n;i++){//through counts.
            for(int j=i;j<=n;j=j+i){//through jumps.
                counts[j]=counts[j]+jumps[i];
            }
        }

        cout<<*max_element(all(counts))<<endl;
    }
    return 0;
}