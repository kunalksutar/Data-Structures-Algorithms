#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){

    struct Rectangle a;
    struct Rectangle *p=&a;

    p = new struct Rectangle; //this allot a memory in heap.
    //And the address to this memory in heap will be stored in p.

    p->length = 10;
    p->breadth = 5;

    cout<<"";

    return 0;
}