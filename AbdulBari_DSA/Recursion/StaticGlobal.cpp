#include<iostream>
using namespace std;

int fun(int n){
static int x = 0;
    if(n>0){//base condition
        x++;
        return fun(n-1)+x;
    }
return 0;//it will return 0 for the termination case. we can skip line, won't make any difference.
}

int main(){

    cout<<fun(5);
    return 0;
}