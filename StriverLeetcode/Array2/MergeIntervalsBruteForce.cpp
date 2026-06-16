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

vector<vector<int>>merge(vector<vector<int>>&intervals){
    int n=intervals.size();
    vector<vector<int>>result;
    sort(intervals.begin(),intervals.end());
    result.push_back(intervals[0]);
    for(int i=1;i<n;i++){
        if(intervals[i][0]<=result.back()[1] && intervals[i][1]>result.back()[1])
            result.back()[1]=intervals[i][1];
        else if(intervals[i][0]>result.back()[1])
            result.push_back(intervals[i]);
    }return result;
}

void display(vector<vector<int>>matrix){
    for(vector<int>vec:matrix)
        cout<<"("<<vec[0]<<","<<vec[1]<<")";
}

int main(){
vector<vector<int>>matrix={{1,4},{4,5}};
display(merge(matrix));
return 0;
}