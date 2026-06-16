#include<iostream>
using namespace std;

struct Stack{
    private:
        int size;
        int top;
        int *s;
    public:
        Stack(){//constructor
            cout<<"Enter the size :";
            cin>>size;

            top=-1;

            s=new int[size];
        }

        void push(int val){
            if(top==size-1){//meaning if the stack is filled to the top.
                cout<<"Stack-Overflow";
            }else{
                s[++top]=val;
            }
        }

        int pop(){
            int x=-1;
            if(top==-1){
                cout<<"Stack-Underflow : ";
            }else{
                x=s[top--];
            }
            return x;
        }

        int peek(int pos){
            int x=-1;
            if(top-pos+1<0){
                cout<<"Invalid postion : ";
            }else{
                x=s[top-pos+1];
            }
            return x;
        }

        int stackTop(){
            if(top==-1){
                return -1;
            }else{
                return s[top];
            }
        }

        bool isEmpty(){
            if(top==-1){
                return true;
            }else{
                return false;
            }
        }

        bool isFull(){
            if(top==size-1){
                return true;
            }else{
                return false;
            }
        } 
};

int main(){
struct Stack s;
s.push(5);
s.push(11);
s.push(4);
cout<<s.pop();

    return 0;
}