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
    int n;cin>>n;
    int prev;cin>>prev;
    int ans=1,count=0;
    bool flag=true;
    for(int i=1;i<n;i++){
        int curr;cin>>curr;
        if(curr>=prev){
            if(flag){
                count+=2;
                flag=false;
            }else count++;
            ans=max(ans,count);
        }else{
            count=0;
            flag=true;
        }
        prev=curr;
    }
    cout<<ans<<endl;
}

int main(){
int t=1;
while(t--)solve();
return 0;
}