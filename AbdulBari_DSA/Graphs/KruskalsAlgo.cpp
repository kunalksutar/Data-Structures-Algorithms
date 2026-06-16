#include<iostream>
#define I INT32_MAX
using namespace std;
 
int edges[3][9]={{ 1, 1, 2, 2, 3, 4, 4, 5, 5}, //first node.
                { 2, 6, 3, 7, 4, 5, 7, 6, 7}, //second node.
                {25, 5,12,10,18,16,14,20,18}};//the cost of the link.
int n=7;//number of nodes.
int e=9;//number of edges present inside the graph.
int set[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int included[9]={0};
int t[2][6];

int find(int u){//for the given node u, will return the head/parent node.
    int x=u;
    while(set[x]>0)x=set[x];//will keep searching for the head node.
    return x;
}

void setUnion(int u,int v){//where u and v are the head/parent node of the sets.
    if(set[u]>set[v]){//meaning v is the parent node.
        set[v]=set[v]+set[u];//since the number of nodes contained will increase.
        set[u]=v;//also this will point to the new parent node.
    }else{//same but reverse here.
        set[u]=set[v]+set[u];
        set[v]=u;
    }
}

int main(){

int i=0;
    while(i<n-1){//since we want to find n-1 number of edges, we will run this loop n-1 times.
    //in each loop, we will try to find the next lowest cost link.
        int min=I;int u,v,k=0;
        for(int i=0;i<e;i++){
            if(included[i]==0 && min>edges[2][i]){
                min=edges[2][i];
                k=i;u=edges[0][i];v=edges[1][i];
            }
        }

        if(find(u)!=find(v)){
            t[0][i]=u;t[1][i]=v;
            setUnion(find(u),find(v));//we will merge the parents.
            i++;
        }
        included[k]=1;//meaning we won't visit this node again as we have seen that pair.
    }
    for(int i=0;i<6;i++){cout<<"("<<t[0][i]<<","<<t[1][i]<<") ";}
return 0;
}