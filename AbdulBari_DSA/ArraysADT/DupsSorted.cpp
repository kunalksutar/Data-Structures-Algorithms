#include<iostream>
using namespace std;
 
struct Array {
    int A[10];
    int size;
    int length;
};

void dups(struct Array arr){
    int* hash;
    hash = new int[21]{0};//initializing a array of size 10 in heap with all zeros

    for(int i = 0 ; i<arr.length ; i++){
        hash[arr.A[i]]++;//first we will update the hash.table
    }

    for(int i = 0; i < 21 ; i++){
        if(hash[i]>1)cout<<i<<" repeated "<<hash[i]<<" times."<<endl;
    }

    delete []hash;//DO NOT FORGET TO DELETE!!!
}

int main(){

struct Array arr={{3,6,8,8,10,12,15,15,15,20},10,10};

dups(arr);
return 0;
}