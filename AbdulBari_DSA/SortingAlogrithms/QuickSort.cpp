#include<iostream>
using namespace std;

void display(int A[],int n){for(int i=0;i<n;i++)cout<<A[i]<<" ";cout<<endl;}
void swap(int& x, int& y){int temp=x;x=y;y=temp;}

int partition(int A[],int l,int h){
    int pivot=A[l];
    int i=l,j=h;

    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j)swap(A[i],A[j]);//if j<i them we simply do nothing,
        //because the next loop won't be executed and exit the loop.
    }while(i<j);
    swap(A[l],A[j]);
    return j;
}

void quickSort(int A[],int l,int h){
    if(l<h){
        int i=partition(A,l,h);
        quickSort(A,l,i);//we must have written i-1 here but we won't do that.
        //because at index i, there will be the highest element for that partition...
        //and will act as the highest element, or should I say infinity. 
        quickSort(A,i+1,h);//look here at h index, we have given infinity.
    }
}


int main(){
    int A[]={12,43,52,55,2,17,32,14,19,INT32_MAX};//we add this int32_max at end to
    //act as infinity.
    display(A,9);

    quickSort(A,0,9);
    display(A,9);
    
return 0;
}