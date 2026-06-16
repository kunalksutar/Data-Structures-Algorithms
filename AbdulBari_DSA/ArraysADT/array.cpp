#include<iostream>
using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

void DisplayArray(struct Array arr){
    cout<<"Elements in the array are : ";
    for(int i = 0; i<arr.length ; i++){
        cout<<arr.A[i]<<" ";
    }
}

int main(){

struct Array arr;
int arr_size;
cout<<"Enter array size :";
cin>>arr_size;//prompt

arr.A = new int[arr_size];
arr.length=0;//since initially there will be no elements added in the array.

cout<<"Enter number of elements to add :";
cin>>arr.length;

cout<<"Enter all the numbers you want to add :";
for(int i = 0 ; i<arr.length ; i++){
    cin>>arr.A[i];
}

DisplayArray(arr);

return 0;
}