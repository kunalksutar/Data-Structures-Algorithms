#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

bool DFS(int i,int j,int fuel,vector<vector<int>>&board,int x){
    if(fuel==0)return false;//out of fuel
    else if(j<0||i>=board.size())return false;//out of boundary
    else if(board[i][j]!=-1)return false;//already occupied by someone

    board[i][j]=x;
    if(!DFS(i,j-1,fuel-1,board,x)){
        DFS(i+1,j,fuel-1,board,x);
    }

    return true;
}

int main(){
int n;cin>>n;
    vector<vector<int>>board(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        int x;cin>>x;
        DFS(i,i,x,board,x);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<board[i][j]<<" ";
        }cout<<endl;
    }
return 0;
}