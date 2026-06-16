#include<iostream>
using namespace std;

int main(){
    cout<<"hellow";
    int A[10]={4,56,76,3,1};
    
    for(int i=0;i<10;i++){
        cout<<A[i]<<endl;
    }
    
    for(int x:A){
        cout<<x<<endl;
    }
    return 0;
}
