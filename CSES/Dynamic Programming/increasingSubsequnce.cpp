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

int main(){
int n;cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++)cin>>arr[i];
vector<int>ans;

//GREAT explanation in the below video.
//https://www.youtube.com/watch?v=XhzQHpGcQg4
//also keep in mind that the ans vector will not contain
//the LIS but rather store the correct length of the LIS
//The same youtuber has uploaded another video to print the LIS

for(int i=0;i<n;i++){//leading pointer 
    if(ans.size()==0||ans.back()<arr[i]){
        ans.push_back(arr[i]);
    }else{
        auto it=lower_bound(ans.begin(),ans.end(),arr[i]);
        *it=arr[i];
    }
}cout<<ans.size();
return 0;
}