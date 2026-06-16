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

void PowerSet(string&s){
    int n=s.size();
    for(int num=0;num<pow(2,n);num++){
        string sub;
        for(int i=0;i<n;i++){
            if(num & (1<<i))sub+=s[i];
        }cout<<sub<<endl;
    }return;
}

int main(){
string s="kunal";
PowerSet(s);
return 0;
}