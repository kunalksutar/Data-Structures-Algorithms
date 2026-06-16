#include<iostream>
using namespace std;

struct Array{

    int A[14];
    int size;
    int length;
};

int missing_el(struct Array arr){
    int sum = 0;
    int n = arr.length; 
    for(int i = 0 ; i < n ; i++){
        sum+=arr.A[i];
    }
    int desired_sum = n*(n+1)/2 ;

    if(desired_sum-sum!=0)
        return desired_sum-sum;
}

int missing_el_m2(struct Array arr){
    int diff = arr.A[0]-0;
    for(int i = 0 ; i < arr.length ; i++){
        if(arr.A[i]-i!=diff)
            return i+diff;
    }
}

void missing_els_m1(struct Array arr){
    int diff = arr.A[0]-0;
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]-i!=diff){
            while(diff<arr.A[i]-i){//we will run the loop that many times. 
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }
}


int main(){
    struct Array arr;
    arr={{1,2,3,4,5,6,7,9,10,11,12,13},14,13};

    struct Array arr2={{6,7,8,9,11,12,15,16,17,18,27},11,11};


    cout<<"missing element : "<<missing_el_m2(arr)<<endl;
  
return 0;
}

