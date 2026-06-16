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

struct Array merge_arrays(struct Array arr1,struct Array arr2){
    int m = arr1.length;
    int n = arr2.length;

    int i = 0;//will iterate through the arr1.
    int j = 0;//through arr2.
    int k = 0;//through the new array 'result'

    struct Array result={{0},m+n,m+n};//will create a matrix with size m+n...
    //filled with matrix.

    while(i<m && j<n){
        if(arr1.A[i]>arr2.A[j])
            result.A[k++]=arr2.A[j++];
        else
            result.A[k++]=arr1.A[i++];

    }

    while(i<m){
        result.A[k++]=arr1.A[i++];
    }
    while(j<n){
        result.A[k++]=arr2.A[j++];

    }   
    
    result.size = 10;
    return result;

}

int main(){

    struct Array arr1 = {{12,44,59,60},10,4};
    struct Array arr2 = {{23,45,78,79,80,92},10,6};

    struct Array merged = merge_arrays(arr1,arr2);
    DisplayArray(merged);
    return 0;
}