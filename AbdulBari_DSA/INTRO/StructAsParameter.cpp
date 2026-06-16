#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth; 
};

void fun(struct Rectangle *r1){
r1->length = 50;
r1->breadth = 11;
}

int main(){
struct Rectangle r = {10,5};
fun(&r);
cout<<"length and breadth are :"<<r.length<<" "<<r.breadth;

return 0;
}