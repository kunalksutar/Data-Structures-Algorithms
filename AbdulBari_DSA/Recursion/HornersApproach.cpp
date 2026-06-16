#include<iostream>
using namespace std;

float exp_recurr(float x,int n){
static float s=1;
    if(n>0){
        s=1+(s*x/n);
    return exp_recurr(x,n-1);
    }else{
        return s;
    }
}

int main(){

    cout<<exp_recurr(2,10);
    return 0;
}