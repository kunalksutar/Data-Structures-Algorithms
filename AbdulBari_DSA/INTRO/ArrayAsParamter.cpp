#include<iostream>
using namespace std;

void fun(int A[],int n){
//or even the following will work.
//void fun(int A*){
A[0]=25;
}

int* fun1(int size){
    int* p;
    p = new int [size]; //will create an array in heap memory.

    for(int i = 0 ; i<size ; i++)
        p[i]=i+4;

    return p; 
}

int main(){
    int A[] = {2,4,6,8,10};
    fun(A,5);
    //for(int x:A){
       // cout<<x<<" ";
    //}
    
    int* ptr;
    int n = 10;
    ptr = fun1(n);

    for(int i=0;i<n;i++)
        cout<<ptr[i]<<" ";

    return 0;
}