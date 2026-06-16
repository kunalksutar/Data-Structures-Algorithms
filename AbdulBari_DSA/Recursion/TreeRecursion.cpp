#include<iostream>
using namespace std;

void fun(int n){
    if(n>0){//base conditon.
        cout<<n;
        fun(n-1);
        fun(n-1); 
    }
}

int main(){

return 0;
}