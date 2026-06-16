#include<iostream>
using namespace std;

struct Array{
    int A[10];//we will fix the size here itself.
    int size;
    int length;
};

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void DisplayArray(struct Array arr){
    cout<<"Elements in the array are : ";
    for(int i = 0; i<arr.length ; i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

int LinearSearch(struct Array *arr,int key){//we are passing by address since, we want to updated if we found key.
    for(int i = 0 ; i < arr->length ; i++ ){
        if(arr->A[i]==key){
            swap(&arr->A[i],&arr->A[0]);
            return 0;
        }
    }
    return -1;
}



int main(){

    struct Array arr={{454,2,74,845,34,45,99},10,7};

DisplayArray(arr);

LinearSearch(&arr,34);
DisplayArray(arr);
    return 0;
}