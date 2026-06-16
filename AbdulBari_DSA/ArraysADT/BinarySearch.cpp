#include<iostream>
using namespace std;

struct Array{
    int A[10];//we will fix the size here itself.
    int size;
    int length;
};


void DisplayArray(struct Array arr){
    cout<<"Elements in the array are : ";
    for(int i = 0; i<arr.length ; i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

int BinarySearch(struct Array *arr, int low, int high, int key){
    //The reason why I am calling this function by address is because if I pass it normally ...
    //it will consume more space, since it will create new locations in the stack. 
    //where as here it will reuse the locations, won't create any.
    
    if(low<=high){
        int mid = (low+high)/2;
        if(arr->A[mid]==key){
            return mid;
        }else if(arr->A[mid]>key){
            return BinarySearch(arr, mid+1, high,key);
        }else{
            return BinarySearch(arr, low, mid-1,key);
        }
    }
    return -1;
}


int main(){

    struct Array arr={{454,2,74,845,34,45,99},10,7};

DisplayArray(arr);

BinarySearch(&arr,0,6,45);
DisplayArray(arr);
    return 0;
}