#include<iostream>
using namespace std;

void display(int A[],int length){for(int i=0;i<length;i++)cout<<A[i]<<" ";cout<<endl;}
void swap(int& x,int& y){int temp=x;x=y;y=temp;}

void BubbleSort(int A[],int length){
    int flag;
    for(int i=0;i<length-1;i++){//for number of passes
    //since for n elements in a list we perform n-1 passes.
    //there length-1.
    flag=0;
    for(int j=0;j<length-i-1;j++){
        if(A[j]>A[j+1]){//if previous element is greater the successor.
            swap(A[j],A[j+1]);
            flag=1;
            }
        }
    if(flag==0)break;//if we did NOT perform any swap after any given pass.                            //we simply break the loop, meaning the list is sorted.
    }
}

int main(){
    int A[]={12,43,52,55,2,17,32,14,19};
    display(A,9);

    BubbleSort(A,9);
    display(A,9);
    
return 0;
}