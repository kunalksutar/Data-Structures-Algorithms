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

int binSearch(vector<pair<int,int>>&vec,int target,int left,int right){
    while(left<=right){
        int mid=(left+right)/2;
        if(vec[mid].first<target)left=mid+1;
        else if(vec[mid].first>target)right=mid-1;
        else return mid;
    }if(left<vec.size())return left;
    else return -1;
}

int reversePairs(vector<int>&nums){
    int n=nums.size();
    vector<pair<int,int>>vec(n);
    for(int i=0;i<n;i++){
        vec[i].first=nums[i];
        vec[i].second=i;
    }sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++)cout<<vec[i].first<<" ";cout<<endl;
    for(int i=0;i<n;i++)cout<<vec[i].second<<" ";cout<<endl;

    int target,index=-1,ans=0;
    for(int i=0;i<n;i++){
        target=2*vec[i].first;
        if(target>vec[n-1].first)return ans;
        index=binSearch(vec,target,i+1,n-1);
        //cout<<index;
        if(index==-1)return ans;
        while(vec[index].first==target){
            index++;
            //cout<<index;
        }
        if(index>=n)return ans;
        else{
            while(index<n){
                if(vec[i].second>vec[index].second){
                    ans++;
                }index++;
            }
        }
    }return ans;
}

int main(){
vector<int>vec={1,2,1,2,1};
cout<<reversePairs(vec);
return 0;
}