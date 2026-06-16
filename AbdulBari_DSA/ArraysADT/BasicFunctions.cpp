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

int get(struct Array arr, int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }else{
        return -1;
    }
}

void set(struct Array* arr,int index, int val){
    if(index>=0 && index<arr->length){
        arr->A[index]=val;
    }
}

int max(struct Array arr){
    int max = arr.A[0];
    for(int i = 1 ; i<arr.length ; i++){
        if(max<arr.A[i])
            max = arr.A[i];
    }
    return max;
}

int min(struct Array arr){
    int min = arr.A[0];
    for(int i = 1 ; i<arr.length ; i++){
        if(min>arr.A[i])
            min = arr.A[i];
    }
    return min;
}

int sum_itr(struct Array arr){//iterative method.
    int sum = 0;
    for(int i=0;i<arr.length;i++){
        sum+=arr.A[i];
    }
    return sum;
}

int sum_recurr(struct Array arr,int length){
    if(length>0){
        return sum_recurr(arr,length-1)+arr.A[length-1];
    }else{
        return 0;//for the base case.
        
    }
}

int main(){

struct Array arr={{454,2,74,845,34,45,99},10,7};

set(&arr,2,69);
DisplayArray(arr);

cout<<sum_itr(arr)<<endl;
cout<<sum_recurr(arr,arr.length);
    return 0;
}