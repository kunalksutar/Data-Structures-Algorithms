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

int longestConsecutive(vector<int>&nums){
    //NOTE: This is not the most optimal one because we are using set here instead of
    //unordered_set.
    set<int>st;
    int prev_element=INT32_MAX;//will store the minimum element from the list.
    for(int element:nums){
        st.insert(element);
        if(prev_element>element)prev_element=element;
    }
    int ans=1,curr=ans;
    for(int curr_element:st){//first:what element it is.
    //second:How many times does it occur in the list.
        if(curr_element==prev_element+1)curr++;
        else if(curr_element==prev_element)continue;
        else curr=1;
        prev_element=curr_element;
        ans=max(ans,curr);
    }return ans;
}

int main(){
vector<int>nums={0,3,7,2,5,8,4,6,6,0,1,0,0};
cout<<longestConsecutive(nums);
return 0;
}