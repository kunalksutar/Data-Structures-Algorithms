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

int findMax(map<int,int>&mp,int num){
    auto it=mp.lower_bound(num);
    if(it==mp.begin())return 0;
    else it--;
    return it->second;
}

void insert(map<int,int>&mp,int num,int new_len){
    if(mp[num]>=new_len)return;
    else{
        mp[num]=new_len;
        //after this we will be deleting the elements that are
        //greater than the current element and have lesser advantage
        //than the current element that we just added.
        //because there can be such element that will be higher in 
        //mag but give less advanatae. 

        //The whole point of this data structure is to store elemnets
        //in the increasing order of mag as well as the advantage must \
        //be in increasing order as well.
        auto it=mp.find(num);
        it++;
        while(it!=mp.end() && it->second<=new_len){
            auto temp=it;it++;
            mp.erase(temp);
        }
    }
}

//https://www.youtube.com/watch?v=wqLwv7E1GF0

int main(){
int n;cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++)cin>>arr[i];
map<int,int>mp;
// {num,freq}
int ans=0;
for(int i=0;i<n;i++){
    int freq=1+findMax(mp,arr[i]);
    insert(mp,arr[i],freq);
    ans=max(ans,freq);
}cout<<ans;
return 0;
}