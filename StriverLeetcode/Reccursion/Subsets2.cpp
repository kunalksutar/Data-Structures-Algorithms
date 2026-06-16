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

vector<vector<int>>subsetsWithDup(vector<int>&nums){
        set<vector<int>>st;int n=nums.size();
        for(int num=0;num<pow(2,n);num++){
            vector<int>sub;
            for(int i=0;i<n;i++){
                if(num&(1<<i))sub.push_back(nums[i]);
                sort(sub.begin(),sub.end());
                st.insert(sub);
            }
        }
        vector<vector<int>>result;
        for(vector<int>element:st)result.push_back(element);
        return result;
    }

int main(){
return 0;
}