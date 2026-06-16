#include<iostream>
using namespace std; 

int F[10];//writing the memoization array here so that the fib() function can also use it.
//but this array will hold -1 everywhere. how ? well, we know that when we run a code, it will always start from...
//the int main(). In that, before calling fib() we have initialized the array as -1.

int fib(int n){

    if(n<=1){
        //since we already know what are the values of fib(0) and fib(1).
        F[n]=n;
        return n;//return value for recursion.
    }else{//meaning if the value if 'n' is not 0 or 1.
    
        if(F[n-2]==-1)//if we don't know the value, we will call the function.
            F[n-2]=fib(n-2);
        if(F[n-1]==-1)//same here.
            F[n-1]=fib(n-1);
        
    return F[n-2]+F[n-1];
    }

}

int main(){

int F[10];//notice we are intializing the array globaly...
for(int i=0;i<10;i++)//And setting all values to -1. meaning no fib function has been called yet. 
    F[i]=-1;

cout<<fib(6)<<endl;
cout<<fib(5);

    return 0;
}