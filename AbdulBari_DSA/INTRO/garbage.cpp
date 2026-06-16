#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

struct Rectangle* fun(){
    // This function will create a pointer to a struct Rectangle in heap.
    struct Rectangle* p;
    p = new struct Rectangle; //here.
    p->length = 15;
    p->breadth = 16;
    return p;
}

int main(){
struct Rectangle*r =fun();
cout<<r->length<<endl<<r->breadth;
return 0;
}