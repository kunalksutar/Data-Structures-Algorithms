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

int findDuplicate(vector<int>&nums){
    //NOTE!!! IMPORTANT!!!
    //The below code works correctly and will run all the test cases but will be very slow.
    //Even though we are using undordered map which takes O(1) time to access and insert elements.
    //The problem is that there are too many collisions in the unordered_map and due to
    //collisions it takes ~log(n) time to insert elements.
    unordered_map<int,int>count;
    int ans;
    for(int element:nums){
        if(count[element]!=0){
            ans=element;
            break;
        }else count[element]++;
    }return ans;
}

int main(){
vector<int>nums={3,1,4,2,2};
cout<<findDuplicate(nums);
return 0;
}