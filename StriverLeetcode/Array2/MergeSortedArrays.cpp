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

void merge(vector<int>&nums1,int m,vector<int>&nums2,int n){
    int lowerLimit=-1;
    for(int j=m;j<m+n;j++){//j through nums1
        int i=j-1;
        while(nums1[i]>=nums2[j-m] && i>lowerLimit){
            nums1[i+1]=nums1[i];
            i--;
        }nums1[i+1]=nums2[j-m];
        lowerLimit=i+1;
    }
}

void display(vector<int>vec){
    for(int element:vec)cout<<element<<" ";
    cout<<endl;
}

int main(){
vector<int>v1={1,2,3,0,0,0};
vector<int>v2={2,5,6};
merge(v1,3,v2,3);
display(v1);
return 0;
}