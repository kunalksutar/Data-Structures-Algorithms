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

map<char,int>validNum(vector<vector<char>>&board,int n,int row,int col){
    map<char,int>count;
    for(int i=0;i<n;i++)if(board[row][i]!='.')count[board[row][i]]++;
    for(int i=0;i<n;i++)if(board[i][col]!='.')count[board[i][col]]++;   
    return count;        
}
void recurr(vector<vector<char>>&board,int n,int row,int col){
    if(col==n&&row<n-1){
        col=0;row++;
    }else if(row==n-1&&col==n)return;
    
    if(board[row][col]=='.'){
        map<char,int>count=validNum(board,n,row,col);
        for(auto &element:count){
            if(element.second==0){
                board[row][col]=element.first;
                recurr(board,n,row,col+1);
                board[row][col]='.';
            }
        }
    }else recurr(board,n,row,col+1);
}
void solveSudoku(vector<vector<char>>&board){
    int n=9;
    recurr(board,n,0,0);
}

void printBoard(vector<vector<char>>&board,int n){
    for(vector<char>&vec:board){
        for(char&element:vec){
            cout<<element<<" ";
        }cout<<endl;
    }
}
int main(){
    /*vector<vector<char>>board={
        {"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
        };*/
        cout<<201/21;

return 0;
}