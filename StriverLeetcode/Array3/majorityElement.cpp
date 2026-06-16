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
    int count=0;
    int ans;
    for(int num:nums){
        if(count==0)ans=num;
        if(ans==num){
            count++;
        }else count--;
    }return ans;
}

int main(){
vector<int>nums={5,6,1,4,9,9,7,7,7,7,7,7,7,9};
cout<<majorityElement(nums);
return 0;
}