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

int trap(vector<int>&height){
    int n=height.size();if(n<3)return 0;
    vector<int>A(n);//max from the right.
    int max=height[0];
    for(int i=0;i<n;i++){
        if(max<height[i])max=height[i];
        A[i]=max-height[i];
    }
    //now we will approach from the right.
    max=height[n-1];int ans=0;
    for(int i=n-1;i>=0;i--){
        if(max<height[i])max=height[i];
        ans+=min(A[i],max-height[i]);
    }return ans;
}

int main(){
vector<int>A={4,2,0,3,2,5};
cout<<trap(A);
return 0;
}