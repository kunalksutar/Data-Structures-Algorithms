#include<iostream>
using namespace std;

float exp(float x,int n){
    static float p=1; 
    static int f=1;
    if(n==0){
        return 1;
    }else{
        p=p*x;
        f=f*n;
        return exp(x,n-1)+(p/f);
    }

}

int main(){
    int x=2;
    int n=4;
    cout<<exp(x,n);
    return 0;
}