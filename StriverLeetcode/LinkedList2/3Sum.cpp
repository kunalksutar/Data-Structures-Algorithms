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

vector<vector<int>>threeSum(vector<int>&nums){
    sort(nums.begin(),nums.end());int n=nums.size();
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        int j=i+1,k=n-1;
        while(k>j){
            long long sum=nums[i];
            sum+=nums[j];sum+=nums[k];
            if(sum==0){
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;k--;
                while(nums[j]==nums[j-1])j++;
                while(nums[k]==nums[k+1])k--;
            }else if(sum>0)k--;
            else j++;
        }
    }return ans;
}

int main(){
int n;cin>>n;
return 0;
}