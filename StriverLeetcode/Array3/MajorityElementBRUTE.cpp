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

int majorityElement(vector<int>&nums){
    unordered_map<int,int>count;
    for(int i=0;i<nums.size();i++){
        if(count[nums[i]]>=nums.size()/2)
            return nums[i];
        else count[nums[i]]++;
    }return -1;
}

int main(){
vector<int>nums={2,2,1,1,1,2,2,2};
cout<<majorityElement(nums);
return 0;
}