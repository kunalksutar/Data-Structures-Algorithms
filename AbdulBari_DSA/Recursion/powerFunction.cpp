#include<iostream>
using namespace std;

int pow(int m,int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){//when n is a even number.
        return pow(m*m,n/2);
    }else{
        return pow(m*m,(n-1)/2)*m;
    }
}

int main(){
    cout<<pow(5,6);
    return 0;
}