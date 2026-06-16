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

int uniquePaths(int m,int n){
    //actually we have to calculate (m+n-2)C(m-1)
    //we express that as (high)C(low)
    int high=m+n-2;
    int low=(m<n)?m-1:n-1;//so that we calculate it even faster.
    if(low==0)return 1;
    int ans=1;
    for(int i=1;i<=low;i++){
        ans*=(high-i+1);
        ans/=i;
    }return ans;
}

int main(){
cout<<uniquePaths(3,7);
return 0;
}