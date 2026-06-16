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
int n,m,k;cin>>n>>m>>k;
vector<int>wish(n),alot(m);
for(int i=0;i<n;i++){
    int x;cin>>x;
    wish[i]=x;
}

for(int i=0;i<m;i++){
    int x;cin>>x;
    alot[i]=x;
}

sort(wish.begin(),wish.end());
sort(alot.begin(),alot.end());
int i=0,j=0,ans=0;

while(i<n && j<m){
    if(alot[j]<=wish[i]+k && alot[j]>=wish[i]-k){
        i++;
        j++;
        ans++;
    }else if(alot[j]<wish[i]-k)j++;
    else i++;
}cout<<ans;
return 0;
}