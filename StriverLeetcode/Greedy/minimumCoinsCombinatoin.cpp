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

vector<int>minCoins(vector<int>coins,int sum){
    sort(coins.begin(),coins.end());

    vector<int>ans;int i=coins.size()-1;
    while(sum>=0 && i>=0){
        if(coins[i]<=sum){
            ans.push_back(coins[i]);
            sum-=coins[i];
        }else i--;
    }return ans;
}

void displayVec(vector<int>&vec){for(int& element:vec)cout<<element<<" ";}

int main(){
vector<int>coins={1,2,5,10,20,50,100,500,1000};
int sum=87;vector<int>res=minCoins(coins,sum);
displayVec(res);
return 0;
}