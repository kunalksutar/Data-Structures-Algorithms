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

vector<int>majorityElement(vector<int>&nums){
    //we will only be using 2 pointers since we know there can be atmax 2 elements with...
    //their count greater thn n/3.
    int count1=0,count2=0;
    int el1=INT32_MIN,el2=INT32_MIN;
    for(int element:nums){
        if(count1==0 && element!=el2){
            count1=1;el1=element;
        }else if(count2==0 && element!=el1){
            count2=1;el2=element;
        }else if(element==el1){
            count1++;
        }else if(element==el2){
            count2++;
        }else{
            count1--;count2--;
        }
    }//after this we will be storing 2 elements in el1 and el2.
    //just to make sure that they are present more than n/3 times in the list.
    //We again traverse through the list and find the count for each.

    count1=0;count2=0;
    for(int element:nums){
        if(element==el1)count1++;
        if(element==el2)count2++;
    }

    vector<int>result;
    if(count1>(nums.size()/3))result.push_back(el1);
    if(count2>(nums.size()/3))result.push_back(el2);
    sort(all(result));
    return result;
}

int main(){
int n;cin>>n;
return 0;
}