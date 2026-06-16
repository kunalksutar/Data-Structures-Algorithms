#include<iostream>
using namespace std;

void display(int A[],int length){for(int i=0;i<length;i++)cout<<A[i]<<" ";cout<<endl;}
void swap(int& x,int& y){int temp=x;x=y;y=temp;}

void selectionSort(int A[],int length){
    for(int i=0;i<length-1;i++){
        int k=i;
        for(int j=i;j<length;j++){
            //k will initially point at i.
            //and j will iterate through the whole elements 
            //we will make k point the index of lowest number.
            if(A[j]<A[k])k=j;
        }
        swap(A[k],A[i]);
    }
}

int main(){
int A[]={12,43,52,55,2,17,32,14,19};
    display(A,9);

    selectionSort(A,9);
    display(A,9);
return 0;
}