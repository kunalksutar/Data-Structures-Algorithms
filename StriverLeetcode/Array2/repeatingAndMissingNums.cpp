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

void repeatedNumber(vector<int>&A, int n){
    map<int,int>count;
    for(int i=0;i<n;i++){
        count[A[i]]++;
        if(count[A[i]]==2)cout<<A[i]<<" ";
    }
    for(int i=0;i<n;i++)
        if(count[i]==0)cout<<i;
}

int main(){

return 0;
}