#include<iostream>
using namespace std;

int max_val(int A[],int n){int max=A[0];for(int i=1;i<n;i++)if(A[i]>max)max=A[i];return max;}
void display(int A[],int length){for(int i=0;i<length;i++)cout<<A[i]<<" ";cout<<endl;}

void countSort(int A[],int n){
    int max=max_val(A,n);
    int* count=new int[max];
    
    for(int i=0;i<max+1;i++)count[i]=0;//initializing the whole count array to 0
    for(int i=0;i<n;i++)count[A[i]]++;

    int i=0;//through count.
    int k=0;//through A array.
    while(i<max+1){
        if(count[i]>0){
            A[k++]=i;
            count[i]--;
        }else i++;
    }
}

int main(){
    int A[]={12,43,52,55,2,17,32,14,19};
    display(A,9);

    countSort(A,9);
    display(A,9);

return 0;
}