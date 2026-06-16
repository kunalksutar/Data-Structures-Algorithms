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

int findMaxConsecutiveOnes(vector<int>&nums){
    int n=nums.size();
    int ans=0,curr=0;
    for(int i=0;i<n;i++){
        if(nums[i]==1)curr++;
        else curr=(nums[i]==1)?1:0;
        ans=max(ans,curr);
    }return ans;
}

int main(){
int n;cin>>n;
return 0;
}