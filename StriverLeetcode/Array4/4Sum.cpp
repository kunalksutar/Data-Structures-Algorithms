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

vector<vector<int>>fourSum(vector<int>&nums,int target){
    int n=nums.size();
    vector<vector<int>>result;
    sort(nums.begin(),nums.end());//O(nlogn)
    int i,j,k,l;
    long long sum;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])continue;//to make sure that we do not get duplicates.
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && nums[j]==nums[j-1])continue;//to make sure we do not get duplicates.
            k=j+1;l=n-1;
            while(k<l){
                sum=nums[i];sum+=nums[j];//we add 
                sum+=nums[k];sum+=nums[l];
                if(sum==target){
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};//there is no need to
                    //sort this temp vector because it is picked out in order...            
                    //from an already sorted list.
                    result.push_back(temp);
                    k++;l--;//for update the pointers for finding further cases.
                    while(k<l && nums[k]==nums[k-1])k++;//we keep increamenting pushing the pointers
                    while(k<l && nums[l]==nums[l+1])l--;//in order to avoid duplicates
                }else if(sum>target)l--;
                else k++;
            }
        }
    }return result;
}

int main(){
int n;cin>>n;
return 0;
}