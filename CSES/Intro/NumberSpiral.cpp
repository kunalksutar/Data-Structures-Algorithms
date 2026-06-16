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

void solve(){
    int y,x;cin>>y>>x;
    int ans=1;
    for(int i=2;i<=y;i++){
        if(i%2==0)ans+=3+(4*i);
        else ans+=1;
    }ans+=x-1;
    cout<<ans<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}