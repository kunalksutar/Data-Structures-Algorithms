#include<iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth; 
    public: 
        Rectangle(){//called a 'constructor'.
            length=breadth=0;
        }
        int area(){
            return length*breadth;
        }
        int perimeter(){
            return 2*(length+breadth);
        }
        int getlength(){
            return length;
        }
        int getbreadth(){
            return breadth;
        }
        
};

int main(){
    return 0;
}