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

void recurr(vector<vector<int>>&ans,vector<int>&candidates,vector<int>&temp,int target,int sum,int n){
    if(sum==target)ans.push_back(temp);
    else if(sum>target)return;
    for(int i=0;i<n;i++){
        temp.push_back(candidates[i]);
        recurr(ans,candidates,temp,target,sum+candidates[i],n);
        temp.pop_back();
    }return;
}

vector<vector<int>>combinationSum(vector<int>&candidates,int target){
    vector<vector<int>>ans;
    vector<int>temp;int n=candidates.size();
    recurr(ans,candidates,temp,target,0,n);
    return ans;
}

void print(vector<vector<int>>&mat){
    for(vector<int>&vec:mat){
        cout<<"(";
        for(int element:vec)cout<<element<<" ";
        cout<<") ";
    }
}

int main(){
vector<int>candidates={2,3,6,7};
int target=7;
vector<vector<int>>ans=combinationSum(candidates,target);
print(ans);
return 0;
}