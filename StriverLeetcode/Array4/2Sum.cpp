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

vector<int>twoSum(vector<int>&nums,int target){
    unordered_map<int,int>reccord;
    int compliment;
    for(int i=0;i<nums.size();i++){
        compliment=target-nums[i];
        if(reccord.count(compliment)>0)return {i,reccord[compliment]};
        else reccord[nums[i]]=i;
    }return {};
}

int main(){
int n;cin>>n;
return 0;
}