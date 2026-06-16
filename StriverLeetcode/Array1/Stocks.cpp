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

int maxProfit(vector<int>prices){
    int n=prices.size();
    int profit=0;
    int bestPrice=prices[0],curr_deal;
    for(int i=1;i<n;i++){
        curr_deal=prices[i]-bestPrice;
        profit=max(profit,curr_deal);
        bestPrice=min(bestPrice,prices[i]);//updating the minimum so far.
    }return profit;
}

int main(){
cout<<maxProfit({7,1,5,3,6,4});
return 0;
}