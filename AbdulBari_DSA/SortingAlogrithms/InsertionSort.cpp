#include<iostream>
using namespace std;

void display(int A[],int length){for(int i=0;i<length;i++)cout<<A[i]<<" ";cout<<endl;}

void insertionSort(int A[],int length){
    int x;
    for(int i=0;i<length;i++){//i will start from the 2nd element and go till the last.
    //we leave the first element because it is already sorted.
        x=A[i];//the number we want to insert to the left of the array.
        int j=i-1;//j will iterate through the left array starting from just left of i.
        //and make it's way all the way to the first element.(i.e. move to the left)
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }//when this loop will break, j+1 will be pointing at the postion where x must be added.
        A[j+1]=x; 
    }
}

int main(){
    int A[]={12,43,52,55,2,17,32,14,19};
    display(A,9);

    insertionSort(A,9);
    display(A,9);
    
return 0;
}