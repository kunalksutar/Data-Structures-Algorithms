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

void reverse_aux(struct Array* arr){//using auxilary/extra array
int aux[arr->length];
int j=0;//toggle through the auxilary array.
    for(int i = arr->length-1 ; i >=0  ; i--){
        aux[j]=arr->A[i];//copying A in auxilary in reverse order.
        j++;
    }

    for(int i=0; i < arr->length ; i++){
        arr->A[i]=aux[i];//copying the aux as it is onto the orignal one.
    }
}

void reverse_swap(struct Array* arr){
int i = 0;//index starting from the left.
int j = arr->length-1;//index from the right 

for(int i = 0 ; j>i ; i++){
    swap(&arr->A[i],&arr->A[j]);
    j--;
    }//note if the array contains odd number of terms then the centre term will remain unchanged.
}

void left_shift(struct Array* arr){
    for(int i = 0; i <arr->length ; i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=0;

}

void rotate(struct Array* arr){
    int temp = arr->A[0];
    for(int i = 0; i <arr->length ; i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=temp;

}

int main(){
struct Array arr={{454,2,74,845,34,45,99},10,7};

DisplayArray(arr);
rotate(&arr);
DisplayArray(arr);

return 0;
}