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

int dp[35][35];

int nCr(int n,int r){
    if(n==1||r==0||r==n)return 1;
    else if(dp[n][r]!=-1)return dp[n][r];
    else return dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
}

vector<vector<int>>generate(int numRows){
    vector<vector<int>>result;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<numRows;i++){
        vector<int>vec(i+1);
        for(int j=0;j<=i;j++)
            vec[j]=nCr(i,j);
        result.push_back(vec);
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