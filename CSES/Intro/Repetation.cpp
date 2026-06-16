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

}

int main(){
string s;cin>>s;
int ans=1;
int curr=1;
for(int i=1;i<s.size();i++){
    if(s[i]==s[i-1])curr++;
    else curr=1;
    ans=max(ans,curr);
}
cout<<ans;
return 0;
}