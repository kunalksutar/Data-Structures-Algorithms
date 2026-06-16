#include<iostream>
#define I INT32_MAX
using namespace std;
 
int cost[8][8]={{I, I, I, I, I, I, I, I},
                {I, I,25, I, I, I, 5, I},
                {I,25, I, 12, I,I, I, I},
                {I, I,12, I, 8, I, I, I},
                {I, I, I, 8, I,16, I,14},
                {I, I, I, I,16, I,20,18},
                {I, 5, I, I, I,20, I, I},
                {I, I, I, I,14,18, I, I}};
int n=8;//size of the array.
int near[8]={I,I,I,I,I,I,I,I};
int t[2][7];

int main(){
    int min=cost[1][1];
    int u=1,v=1;//we will also store the number on that nodes. meaning...
    //the nodes with the lowest cost.
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(cost[i][j]<min){min=cost[i][j];u=i;v=j;}
        }
    }
    t[0][0]=u;t[1][0]=v;near[u]=near[v]=0;
    //now we will update the near array,
    //the index of the array say 'i' and the value stored inside that array 'near[i]'
    //then to the node i, near[i] is the close.
    for(int i=1;i<=n;i++){
        if(near[i]!=0 && cost[i][u]<cost[i][v]){
            near[i]=u;
        }else near[i]=v;
    }

    for(int i=1;i<n-1;i++){
        int k,min=I;
        for(int j=1;j<=n;j++){//will find out which pair of elements is the closest to.
            if(min>cost[i][near[i]]){min=cost[i][near[i]];k=i;}
        }//now that we have found the pair we want to add, we will add it to the t array.
        t[0][i]=k;t[1][i]=near[k];
        //then we will set it in near to 0,
        near[k]=0;

        //now updating the near array.
        for(int j=1;j<=n;j++)if(near[j]!=0 && cost[j][k]<cost[j][near[j]])near[j]=k;       
    }

    //finally we will print them.
    for(int i=0;i<n-1;i++){
        cout<<"("<<t[0][i]<<","<<t[1][i]<<") ";
    }
return 0;
}