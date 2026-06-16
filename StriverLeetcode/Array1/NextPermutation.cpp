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

void solve(){
}

void swap(int& x,int&y){int temp=x;x=y;y=temp;}

void nextPermutation(vector<int>&nums){
    int n=nums.size(),index;

    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            index=i;
            break;
        }
    }

    for(int j=n-1;j>=index;j--){
        if(nums[j]>nums[index]){
            swap(nums[j],nums[index]);
            break;
        }
    }sort(nums.begin()+index+1,nums.end());
}

void display(vector<int>vec){
    for(int element:vec)cout<<element<<" ";
    cout<<endl;
}

int main(){
    vector<int>vec={2,1,5,4,3,0,0};
    nextPermutation(vec);
    display(vec);

return 0;
}