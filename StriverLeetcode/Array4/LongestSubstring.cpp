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

int lengthOfLongestSubstring(string s){
    int n=s.size();
    unordered_map<char,int>st;
    int ans=0;
    int left=0,right=0;
    while(right<n){
        if(st.find(s[right])!=st.end())//if there is already such element present.
            left=max(st[s[right]]+1,left); 
        st[s[right]]=right;
        ans=max(ans,right-left+1);    
        right++;
    }return ans;
}

int main(){
cout<<lengthOfLongestSubstring("abba");
return 0;
}