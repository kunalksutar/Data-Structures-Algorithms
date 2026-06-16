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

void swap(int&x,int&y){int temp=x;x=y;y=temp;}
void display(vector<vector<int>>&matrix){
    for(vector<int>vec:matrix){
        for(int element:vec)cout<<element<<" ";
        cout<<endl;
    }
}

void transpose(vector<vector<int>>&matrix){
    int n=matrix.size();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            swap(matrix[i][j],matrix[j][i]);
}

void rotate(vector<vector<int>>&matrix){
    transpose(matrix);
    for(vector<int>&vec:matrix)
        reverse(vec.begin(),vec.end());
}

int main(){
    vector<vector<int>>matrix={{1,2,3},
                                {4,5,6},
                                {7,8,9}};
    display(matrix);
    rotate(matrix);

    display(matrix);
return 0;
}