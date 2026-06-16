#include<iostream>
using namespace std;

struct Matrix{
    int A[10];
    int size;
};

void set(struct Matrix* mat,int i,int j,int val){
    if(i==j){
        mat->A[i-1]=val;
    } 
}

int get(struct Matrix mat,int i,int j){
    if(i==j){
        return mat.A[i-1];
    }else{
        return 0;//since it is a diagonal matrix.
    }
}

void display(struct Matrix mat){
    for(int i=0;i<mat.size;i++){
        for(int j=0;j<mat.size;j++){
            if(i==j){
                cout<<mat.A[i]<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){

    struct Matrix mat1;
    mat1.size = 4;

    set(&mat1,1,1,15);
    set(&mat1,2,2,20);
    set(&mat1,3,3,25);
    set(&mat1,4,4,30);


    display(mat1);

return 0;
}