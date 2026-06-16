#include<iostream>
using namespace std;

void display(int A[],int length){for(int i=0;i<length;i++)cout<<A[i]<<" ";cout<<endl;}

void shellSort(int A[],int n){
    for(int gap=n/2;gap>0;gap=gap/2){
        for(int i=gap;i<n;i++){//i is the leading element.
            int j=i-gap;//j will tail the leading element.
            int temp=A[i];//after this part it is kind of like insertionSort.
            while(j>=0 && temp<A[j]){//meaning if the tail element is greater..
            //than the leading element.
            A[j+gap]=A[j];
            j=j-gap;
            }
            A[j+gap]=temp;
        }
    }

}

int main(){
    int A[]={12,43,52,55,2,17,32,14,19};
    display(A,9);

    shellSort(A,9);
    display(A,9);
return 0;
}