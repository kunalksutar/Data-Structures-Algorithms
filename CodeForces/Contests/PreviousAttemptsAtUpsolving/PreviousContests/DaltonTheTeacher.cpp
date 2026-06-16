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
        vector<int>A(n+1);
        int sorted=0;
        for(int i=1;i<=n;i++){
            cin>>A[i];
            if(A[i]-i==0)sorted++;
        }
        cout<<(sorted+1)/2<<endl;
    }
    return 0;
}