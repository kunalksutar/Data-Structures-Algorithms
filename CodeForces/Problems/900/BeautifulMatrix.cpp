#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
int dim=5,x,y;//where x and y are the co-ordinates of 1.
int A[dim][dim];
for(int i=0;i<dim;i++){
    for(int j=0;j<dim;j++){
        cin>>A[i][j];
        if(A[i][j]==1){
            x=i;y=j;
        }
    }
}
cout<<abs(x-2)+abs(y-2);
return 0;
}