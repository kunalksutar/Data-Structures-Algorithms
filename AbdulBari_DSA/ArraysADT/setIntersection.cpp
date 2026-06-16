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

struct Array union_unsort(struct Array arr1, struct Array arr2){
    struct Array result = {{0},10,0};//null array.

    for(int i = 0 ; i<arr1.length ; i++){//copying all the elements of arr1 in result.
        result.A[i]=arr1.A[i];
        result.length++;
    }

    int k = arr1.length; //will iterate through the new merged array.
    
    for(int j = 0 ; j<arr2.length ; j++){//through arr2.
        for(int i = 0 ; i<arr1.length ; i++){//through arr1.
            if(arr2.A[j]==arr1.A[i]){
                j++;//we will skip that number from arr2.
            }else if(arr2.A[j]!=arr1.A[i] && i==arr1.length-1){
                result.A[k++]=arr2.A[j];
                result.length++;
            }
        }
    }

    return result;
}

struct Array union_sorted(struct Array arr1,struct Array arr2){
    int m = arr1.length;
    int n = arr2.length;

    int i = 0;//will iterate through the arr1.
    int j = 0;//through arr2.
    int k = 0;//through the new array 'result'

    struct Array result={{0},10,m+n};//will create a matrix with size m+n...
    //filled with matrix.

    while(i<m && j<n){
        if(arr1.A[i]>arr2.A[j])
            result.A[k++]=arr2.A[j++];
        else if(arr1.A[i]<arr2.A[j])
            result.A[k++]=arr1.A[i++];
        else if(arr1.A[i]==arr2.A[j]){
            result.A[k++]=arr1.A[i];
            i++;
            j++;
        }

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

struct Array intersection_unsort(struct Array arr1,struct Array arr2){
    struct Array result = {{0},10,0};
    int k=0;//through the new result array.

    for(int i = 0; i < arr1.length ; i++){//through arr1.
        for(int j = 0; j < arr2.length ; j++){//through arr2.
            if(arr1.A[i] == arr2.A[j]){
                result.A[k++]=arr1.A[i];
                j=0;//we will reset the iterater to the start and...
                i++;//will search for the next element in the list.
                result.length++;//also increase the length by 1.
            }
        }
    }


    return result;
}

struct Array intersection_sorted(struct Array arr1,struct Array arr2){
    
    struct Array result = {{0},10,0};
    
    int i=0;//through arr1.
    int j=0;//through arr2.
    int k=0;//through the new result array.

    int m = arr1.length;
    int n = arr2.length;

    while(i < m && j < n){
        if(arr1.A[i]<arr2.A[j])
            i++;
        else if(arr1.A[i]>arr2.A[j])
            j++;
        else if(arr1.A[i]==arr2.A[j]){
            result.A[k++]=arr1.A[i];
            i++;
            j++;
            result.length++;
        }

    }

 


    return result;
}



int main(){
struct Array arr1 = {{3,5,10,4,6},10,5};//example of 2 unsorted arrays.
struct Array arr2 = {{12,4,7,2,5},10,5};

DisplayArray(intersection_unsort(arr1,arr2));

struct Array arr3 = {{3,5,10,14,16},10,5};//example of 2 sorted arrays.
struct Array arr4 = {{5,14,17,22,25},10,5};

DisplayArray(intersection_sorted(arr3,arr4));


return 0;
}