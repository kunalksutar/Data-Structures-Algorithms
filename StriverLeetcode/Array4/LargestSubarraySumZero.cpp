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

int maxLen(vector<int>&A,int n){//works for both positives and negatives both.
    map<long long,int>prefixSum;
    int sum=0;
    int ans=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum==0)ans=max(ans,i+1);
        if(prefixSum.find(sum)!=prefixSum.end()){//if there allready exists such number before.
            ans=max(ans,i-prefixSum[sum]);
        }
        if(prefixSum.find(sum)==prefixSum.end()){//if that sum already exits, we will not...
        //add it to the new array. 
            prefixSum[sum]=i;
        }
    }return ans;
}

int main(){
int n;cin>>n;
return 0;
}