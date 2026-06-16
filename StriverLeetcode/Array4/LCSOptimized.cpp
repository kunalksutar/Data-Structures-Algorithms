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
    int n=nums.size();
    unordered_set<int>st;//using unordered set
    for(int i=0;i<n;i++)st.insert(nums[i]);
    int ans=1;
    for(int element:st){
        if(st.find(element-1)==st.end()){//meaning if this is the lowest element
        //of the consecutive string. OR in other words...
        //in the consecutive list in which element belongs, element is not the lowest one.
        //if it is not, then we simply skip counting. why ?
        //since we can only move in forwards direction.
            int count=1;//the element itself.
            int x=element;
            while(st.find(x+1)!=st.end()){
                count++;x++;
            }ans=max(ans,count);
        }
    }return ans;
}

int main(){
vector<int>nums={0,3,7,2,5,8,4,6,6,0,1,0,0};
cout<<longestConsecutive(nums);
return 0;
}