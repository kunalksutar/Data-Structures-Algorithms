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
        int prev,curr,minDiff=INT32_MAX;cin>>prev;
        bool sorted=true;
        for(int i=1;i<n;i++){
            cin>>curr;
            if(curr-prev<0)sorted=false;
            else if(minDiff>curr-prev)minDiff=curr-prev;
            prev=curr;
        }
        if(!sorted)cout<<"0"<<endl;
        else cout<<(minDiff+2)/2<<endl;
    }
    return 0;
}