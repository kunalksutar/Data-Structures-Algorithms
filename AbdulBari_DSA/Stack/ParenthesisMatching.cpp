#include<iostream>
using namespace std;

struct Node {
    public:
        char data;//CHANGED HERE!
        struct Node* next;
};

struct Stack{
    private:
        Node* top;
    public:
        Stack(){//constructor ; initially there will be no elements present.
            top=NULL;
        }

        void push(char val){//CHANGED HERE!
            struct Node* temp = new Node;
            if(temp==NULL){//meaning if the stack is full.
                cout<<"StackOverflow";
            }else{
                temp->data=val;
                temp->next=top;
                top=temp;
            }
        }

        char pop(){//CHANGED HERE!
            char x=-1;//CHANGED HERE!
            struct Node* p;//this will help us delete the node from heap completely.
            if(top==NULL){
                cout<<"StackUnderflow";
            }else{
                p=top;
                x=top->data;
                top=top->next;
                delete p;
            }
            return x;
        }

        int peek(int pos){
            struct Node* p=top;
            for(int i=0;p!=NULL && i<pos-1;i++){
                p=p->next;
            }

            if(p==NULL){
                return -1;
            }else{
                return p->data;
            }
        }

        bool isEmpty(){
            if(top==NULL){
                return true;
            }else{
                return false;
            }
        }//this same function can also be written as follows.

        bool isEmptyNew(){
            return top==NULL ? true : false;
        }

        bool isFull(){
            struct Node* temp = new Node;
            
            return temp==NULL ? true : false ;
        }//this function will although work fine but actually is not good. why? beacuse...
        //we created a new node in heap and didn't delete it at all.
        //let's say we call this function mutliple times inside our program.
        //it will occupy space for no reason.

        bool isFullNew(){
            struct Node* temp = new Node;
            bool result = temp==NULL ? true : false ;
            delete temp;
            return result;
        }//now this is good.

        char stackTop(){
            return top!=NULL ? top->data : -1 ;
        }
};

bool isBalanced(char exp[]){
    struct Stack s;

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            s.push(exp[i]);
        }else if(exp[i]==')'){
            if(s.isEmpty()){//meaning if it is empty then do this...
                return false;
            }else{
                s.pop();
            }
        }
    }

    return s.isEmpty()? true : false;
}

bool isBalancedMixed(char exp[]){
    struct Stack s;
    char x;//this will store the deleted data and compare if it is the same bracket or not.

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            s.push(exp[i]);
        }else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(s.isEmpty()){//checking if stack is empty or not.
                return false;
            }else{
                x=s.pop();
                if(!(x=='(' && exp[i]==')') && !(x=='[' && exp[i]==']') && !(x=='{' && exp[i]=='}')){
                    return false;
                }
            }
        }
    }
    return s.isEmpty() ? true : false;
}

int main(){
    char exp[]="((a+b)*(c-d))";
    char exp1[]="{([a+b]*[c-d])/e}";
    cout<<isBalancedMixed(exp1);
}