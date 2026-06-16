#include<iostream>
using namespace std;

int main(){
    int* p;
    p = new int[5];
    for(int i = 0 ; i<5 ; i++){
        p[i]=i*5;
    }

    int* q;
    q = new int[10];//creating a new array inside heap with larger array length.
    for(int i = 0 ; i<5 ; i++){
        q[i]=p[i];//assigning the first  5 elements same as that of p[];
    }

    delete []p;//since we are dealing with heap, we will release this memory.
    p=q;
    q=NULL;

    for(int i = 0 ; i<10 ; i++){
        cout<<p[i] <<" "; //since we only assign the first 5 elements, the rest will be set as garbage value.
    }

     return 0;
}