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

int removeDuplicates(vector<int>&nums){
    int n=nums.size();if(n<2)return n;
    int k=1,prev_num=nums[0];
    for(int i=1;i<n;i++){
        while(nums[i]==prev_num && i<n)i++;
        if(i==n)return k;
        nums[k++]=nums[i];
        prev_num=nums[i];
    }return k;
}

void display_vec(vector<int>&nums){for(int element:nums)cout<<element<<" ";}

int main(){
vector<int>nums={1,1,1,2,2};
cout<<removeDuplicates(nums)<<endl;
display_vec(nums);
return 0;
}