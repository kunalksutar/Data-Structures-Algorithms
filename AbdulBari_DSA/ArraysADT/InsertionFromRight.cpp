#include<iostream>
using namespace std;

//NOTE!!!!!
//The following functions will only work for arrays that are sorted.

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

void insertion(struct Array* arr,int val){
int i = arr->length-1;
    while(arr->A[i]>val){
        arr->A[i+1]=arr->A[i];
        i--;
        }
    arr->A[i+1]=val;
    arr->length++;
}

bool isSorted(struct Array arr){
    for(int i = 0 ; i<arr.length-1 ;i++){
        if(arr.A[i]>arr.A[i+1])
            return false;
    }
    return true;
}

void negative_to_left(struct Array* arr){
    int i = 0; //start iterating from left.
    //i will find all the positive elements in the left section.
    int j = arr->length-1;//from right.
    //and j will find all the negative elements in right section.

    while(j>i){//since we will stop the algo when i and j cross each other.
        while(arr->A[i]<0)//for -ve elements.
            i++;//skip
        while(arr->A[j]>0)//for +ve elements, 
            j--;//skip
        if(j>i){//When we enter this while loop and...
        //when i and j cross for the last time, it will still swap the elements...
        //which we don't want to happen. 
        //Hence, we write down the same condition inside if again.
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}

int main(){
    struct Array arr = {{3,5,6,11,16,17,19},10,7};

    DisplayArray(arr);

    insertion(&arr,13);
    DisplayArray(arr);

    struct Array messed = {{4,-2,55,-6,-3,4,13},10,7};
    negative_to_left(&messed);

    DisplayArray(messed);

    return 0;
}