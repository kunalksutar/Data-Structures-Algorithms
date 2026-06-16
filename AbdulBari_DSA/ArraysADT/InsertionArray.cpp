#include<iostream>
using namespace std;
struct Array{
    int A[10];//we will fix the size here itself.
    int size;
    int length;
};

void Append(struct Array* arr, int n){
    arr->A[arr->length]=n;
    arr->length++;
}

void DisplayArray(struct Array arr){
    cout<<"Elements in the array are : ";
    for(int i = 0; i<arr.length ; i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

void insertion(struct Array* arr, int index, int val){
    for(int i = arr->length; i>index ; i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[index]=val;
    arr->length++;
}

void deletion(struct Array* arr, int index){
    for(int i = index ; i < arr->length - 1 ; i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->length--;
}

int main(){

struct Array arr = {{33,45,74,23,44,3},10,6};
Append(&arr,69);
DisplayArray(arr);

insertion(&arr,4,420);
DisplayArray(arr);

deletion(&arr,2);
DisplayArray(arr);

return 0;
}