#include<iostream>
using namespace std;

struct Array{

    int A[10];
    int size;
    int length;
};

void print_dups(struct Array arr){
    int latest_dup = 0;
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i]==arr.A[i+1] && arr.A[i]!=latest_dup){//if we found a duplicate
            //and if it is duplicate different from the prev one.
                latest_dup=arr.A[i];
                cout<<latest_dup<<" ";//we print.
            
        }
    }
}

void dup_count(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i]==arr.A[i+1]){
            int j=i+1;
            while(arr.A[i]==arr.A[j])j++;
            cout<<arr.A[i]<<" repeated "<<j-i<<" times."<<endl;
            i=j-1;
        }
    }
}

int main(){
    struct Array arr = {{3,6,8,8,11,11,15,15,15,20},10,10};
    print_dups(arr);
    dup_count(arr);

return 0; 
}