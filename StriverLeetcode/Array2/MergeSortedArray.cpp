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
    for(int i=0;i<n;i++)
        nums1[m+i]=nums2[i];
    sort(nums1.begin(),nums1.end());
}

int main(){

return 0;
}