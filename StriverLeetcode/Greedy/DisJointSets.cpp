#include<bits/stdc++.h>
using namespace std;

struct Disjointset{
private:
    vector<int>rank,parent,size;
public:
    Disjointset(int n){//constructor
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++)parent[i]=i;
    }

    int findParent(int u){
        if(parent[u]==u)return u;
        return parent[u]=findParent(parent[u]);
    }

    void unionBySize(int u,int v){
        int parent_u=findParent(u);
        int parent_v=findParent(v);

        if(parent_u==parent_v)return;
        else if(size[parent_u]>size[parent_v]){
            parent[parent_u]=parent_v;
            size[parent_v]+=size[parent_u];
        }else{
            parent[parent_v]=parent_u;
            size[parent_u]+=size[parent_v];
        }
    }
};

int main(){
return 0;
}