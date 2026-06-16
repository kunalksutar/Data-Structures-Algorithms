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

bool compare(vector<int>&a,vector<int>&b){return a[0]>b[0];}//will sort in reverse order.

int findLongestChain(vector<vector<int>>&pairs){
    int n=pairs.size();if(n==1)return n;
    sort(pairs.begin(),pairs.end(),compare);//O(nlogn)

    int ans=1,curr=1,post_front;
    for(int j=0;j<n;j++){
        post_front=pairs[j][0];
        for(int i=j+1;i<n;i++){
            if(post_front>pairs[i][1]){
                curr++;post_front=pairs[i][0];
            }
        }ans=max(ans,curr);curr=1;
    }return ans;
}

int main(){
    vector<vector<int>>pairs={{1,2},{7,8},{4,5}};
cout<<findLongestChain(pairs);
return 0;
}