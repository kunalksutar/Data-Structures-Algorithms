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

void solve(){

}

vector<int>generatedRow(int n){
    vector<int>result;
    long long ans=1;
    result.push_back(ans);
    for(int r=1;r<=n;r++){
        ans=ans*(n-r+1);
        ans=ans/r;
        result.push_back(ans);
    }
    return result;
}

vector<vector<int>>generate(int numRows){
    vector<vector<int>>result;
    for(int i=0;i<numRows;i++){
        result.push_back(generatedRow(i));
    }return result;
}

void display(vector<vector<int>>vec){
    for(vector<int>v:vec){
        for(int element:v){
            cout<<element<<" ";
        }cout<<endl;
    }
}

int main(){
display(generate(5));
return 0;
}