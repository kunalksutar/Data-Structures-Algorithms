#include<iostream>
using namespace std;

int main(){
    int a=10;
    int* p;
    p=&a;
    cout<<*p<<endl;

    int *p1; // for accessing memory from 'heap'.
    p1 = new int[5];

    p1[0]=10;
    cout<<p[2]<<endl; //this will spit out garbage value.

    //If we are allocating memory from heap, at the end we must delete it from there.
    delete [] p1;

    cout<<sizeof(p1);
    return 0;
}