#include<cstdlib>
#include<iostream>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<list>
#include<deque>
#include<array>
#include<cassert>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
using namespace std;


int main(){
    int n,m;cin>>n>>m;
    vector<int>customers(m);
    multiset<int>ms;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        ms.insert(x);
    }

    for(int i=0;i<m;i++){
        int x;cin>>x;
        auto it=ms.upper_bound(x);
        if(it==ms.begin())cout<<-1<<endl;
        else{
            cout<<*(--it)<<endl;
            ms.erase(it);
        }
    }
return 0;
}