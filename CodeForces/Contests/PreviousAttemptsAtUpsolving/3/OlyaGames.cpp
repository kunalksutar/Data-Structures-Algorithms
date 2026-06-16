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
    int n;cin>>n;
    vector<pair<int,int>>A(n);
    int lowestIndex=0,lowestVal=INT32_MAX;
    //first will store 1st min and second will store 2nd min.
    for(int q=0;q<n;q++){
        int m;cin>>m;
        int x,y;cin>>x>>y;
        if(x>y){A[q].first=y;A[q].second=x;}
        else{A[q].first=x;A[q].second=y;}

        for(int i=0;i<m-2;i++){
            int x;  
            if(x<A[q].first)A[q].first=x;
            else if(x<A[q].second)A[q].second=x;
        }
        //if(A[q].first>lowestVal)
    }
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}