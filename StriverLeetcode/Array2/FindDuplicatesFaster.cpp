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

int findingDuplicate(vector<int>&nums){
    int slow=0,fast=0;
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];
    }while(slow!=fast);

    slow=0;
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return fast;
}

int main(){

return 0;
}