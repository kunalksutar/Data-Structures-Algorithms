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
    int n,x;cin>>n>>x;
    vector<int>w(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        w[i]=x;
    }sort(w.begin(),w.end());
    
    int left=0,right=n-1,ans=0;
    while(left<=right){
        if(w[left]+w[right]<=x){
            left++;
            right--;
            ans++;
        }else{
            right--;
            ans++;
        }
    }cout<<ans;
    return 0;
}