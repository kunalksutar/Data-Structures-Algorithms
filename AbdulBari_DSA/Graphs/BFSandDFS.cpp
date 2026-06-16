#include<iostream>
#include<queue>
using namespace std;

void BFS(int A[][7],int u, int n){//u here can be any node out of the seven nodes.
    queue<int> q;
    int visited[n+1]={0};//initially setting everything to zero.
    //no node has been visited.
    visited[u]=1;
    cout<<u<<" ";
    q.push(u);
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(A[u][i]==1 && visited[i]==0){//if the link is there and the node is not visited.
                visited[i]=1;
                cout<<i<<" ";
                q.push(i);
            }
        }
    }
}


void DFS(int A[][7],int u,int n){
    static int visited[7]={0};
    if(visited[u]==0){
        visited[u]=1;
        cout<<u<<" ";
            for(int i=1;i<=n;i++){
                if(A[u][i]==1 && visited[i]==0){//meaning if the link is there and the...
                //node has not been visited yet.
                    DFS(A,i,6);
                }
            }
    }
}

int main(){// 0 1 2 3 4 5 6  
int num_nodes=6;
int A[7][7]={{0,0,0,0,0,0,0}, //0
             {0,0,1,1,0,0,0}, //1
             {0,1,0,0,1,0,0}, //2
             {0,1,0,0,1,0,0}, //3
             {0,0,1,1,0,1,1}, //4
             {0,0,0,0,1,0,0}, //5
             {0,0,0,0,1,0,0}};//6
    BFS(A,1,6);cout<<endl;
    DFS(A,1,6);
return 0;
}