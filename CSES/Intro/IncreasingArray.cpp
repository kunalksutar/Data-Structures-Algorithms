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
int n;cin>>n;
long long ans=0;
int mx=1;
for(int i=0;i<n;i++){
    int x;cin>>x;
    mx=max(mx,x);
    ans+=mx-x;
}
cout<<ans;
return 0;
}