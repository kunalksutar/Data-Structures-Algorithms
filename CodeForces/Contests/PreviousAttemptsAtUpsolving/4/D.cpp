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
    int a,b,c;cin>>a>>b>>c;
    bool turn=true;//meaning it is A's turn.
    if(c%2!=0)turn=false;

    if(turn && a>b)cout<<"First"<<endl;
    else if(turn && a<=b)cout<<"Second"<<endl;
    else if(!turn && b>a)cout<<"Second"<<endl;
    else if(!turn && b<=a)cout<<"First"<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}