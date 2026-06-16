#include<iostream>
using namespace std;
 
struct Array {
    int A[10];
    int size;
    int length;
};

void dups(struct Array arr){
   
    for(int i=0;i<arr.length;i++){
        int count=1;
        for(int j=i+1;j<arr.length;j++){
            if(arr.A[i]==arr.A[j] && arr.A[i]>-1){
                arr.A[j]=-1;
                count++;
            }
        }

        if(count>1)
            cout<<arr.A[i]<<" repeated "<<count<<" times."<<endl;
    }

    
}

void hash_dups(struct Array arr){
    int* hash;
    hash = new int[9]{0};//initializing a array of size 10 in heap with all zeros
    //since the highest element in the list is 8 so we need 9 size of hash.

    for(int i=0;i<arr.length;i++){
        hash[arr.A[i]]++;//fill the array info onto the hash table.
    }

    for(int i=0;i<9;i++){
        if(hash[i]>1)
            cout<<i<<" repeated "<<hash[i]<<" times."<<endl;
    }

    delete []hash;//DO NOT FORGET TO DELETE!!!

}

int main(){

struct Array arr={{8,3,6,4,6,5,6,8,2,7},10,10};

dups(arr);
hash_dups(arr);
return 0;
}