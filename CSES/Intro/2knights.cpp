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

bool safe(string&s){
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            return true;
        }
    }

    return false;
}

//abcdeedcba

int main(){
    string s="abbaca";
    string ans="";

    ans.push_back(s[0]);

    for(int i=1;i<s.size();i++){
        if(ans.size() && ans.back()==s[i]){
            ans.pop_back();
        }else{
            ans.push_back(s[i]);
        }
    }

    cout<<ans<<endl;
return 0;
}