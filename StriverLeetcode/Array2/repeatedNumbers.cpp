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

void repeatedNumber(vector<int>nums){
    int n=nums.size();
    long long sum=0,sq_sum=0;
    long long sub1=(n*(n+1))/2,sub2=(n*(n+1)*(2*n+1))/6;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        sq_sum+=(long long)nums[i]*(long long)nums[i];
    }
    int val1=sum-sub1;
    int val2=sq_sum-sub2;
    val2=val2/val1;
    cout<<(val1+val2)/2<<" "<<(val2-val1)/2;
}

int main(){
repeatedNumber({1,1,3,4,5});
return 0;
}