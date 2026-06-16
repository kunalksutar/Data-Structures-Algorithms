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

void setZeroes(vector<vector<int>>& matrix){
    //matrix is mxn.
    int n=matrix[0].size();
    int m=matrix.size();

    int ZZel=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0)
                        matrix[0][j]=0;
                    else 
                        ZZel=0;
            }
        }
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][0]==0||matrix[0][j]==0 && matrix[i][j]!=0)
                matrix[i][j]=0;
        }
    }

    if(ZZel==0)
        for(int i=0;i<m;i++)
            matrix[i][0]=0;

    if(matrix[0][0]==0)
        for(int j=0;j<n;j++)
            matrix[0][j]=0;
}

void displayMatrix(vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }cout<<endl;
    }
}

int main(){
    vector<vector<int>>matrix={{0,1,2,0},{3,6,7,1},{9,6,3,7}};
    displayMatrix(matrix);
    cout<<endl;
    setZeroes(matrix);
    displayMatrix(matrix);
return 0;
}