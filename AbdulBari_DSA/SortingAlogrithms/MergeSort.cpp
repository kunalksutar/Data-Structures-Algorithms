#include<iostream>
using namespace std;

void display(int A[],int length){for(int i=0;i<length;i++)cout<<A[i]<<" ";cout<<endl;}

void merge(int A[],int l, int mid, int h){
    int i=l;//through the first half
    int j=mid+1;//through the second half
    int B[h-l+1];//we will need an auxilary array
    int k=0;//through B. intially it will be empty.

    while(i<=mid && j<=h){
        if(A[i]<A[j])B[k++]=A[i++];
        else B[k++]=A[j++];
    }

    while(i<=mid){B[k++]=A[i++];}
    while(j<=h){B[k++]=A[j++];}

    for(int i=l;i<h+1;i++)A[i]=B[i-l];//copying all elements back to A.
}

void mergeSort(int A[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,h);
        merge(A,l,mid,h);
    }

}
int main(){
    int A[]={12,43,52,55,2,17,32,14,19};
    display(A,9);

    mergeSort(A,0,8);
    display(A,9);
return 0;
}