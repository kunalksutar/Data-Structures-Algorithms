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

int countInversion(vector<int>nums){
    int n=nums.size();
    int mid=n/2;
    int p=mid+1;
    int q=n-mid-1;
    //let the length of the first half of the array be p and the second be q;
    sort(nums.begin(),nums.begin()+mid+1);//O(plogp)
    sort(nums.begin()+mid+1,nums.end());//O(qlogq)
    for(int element:nums)cout<<element<<" ";
    cout<<endl;
    int i=0;
    int j=mid+1;
    int ans=0;
    while(i<mid+1 && j<n){
        if(nums[i]>nums[j]){
            ans+=p-i;
            j++;
        }
        if(nums[i]<nums[j])i++;
    }return ans;
}

int main(){
cout<<countInversion({2,5,1,3,4});
return 0;
}