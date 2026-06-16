#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){
    struct Rectangle r={10,5};
    struct Rectangle* p;

    p=&r;
    p->length=20;
    p->breadth=15;

    cout<<r.length<<endl<<r.breadth;


    return 0;
}