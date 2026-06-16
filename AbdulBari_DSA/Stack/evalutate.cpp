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

int strlen(char* string){
    int length;
    for(length=0;string[length]!='\0';length++){
    }
    return length;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;
    }else{
        return 1;
    }
}

int pre(char x){//will return he presidence of the given char.
    if(x=='+' || x=='-'){
        return 1;
    }else if(x=='*'|| x=='/'){
        return 2;
    }
    return 0;
}

char* convert(char* infix){
    struct Stack s;
    char* postfix = new char[strlen(infix)+1];//+1 for the null we will add later.
    int i=0;//will iterate through infix.
    int j=0;//through postfix.

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }else{//meaning if it is an operater.
            if(pre(infix[i])>pre(s.stackTop())){
                s.push(infix[i++]);
            }else{//meaning when the presidence is equal or less.
            //we pop.
                postfix[j++]=s.pop();
            }
        }
    }

    while(!s.isEmpty()){
        postfix[j++]=s.pop();
        }

    postfix[j]='\0';
    return postfix;

}

int evaluate(char* postfix){//exp stands for expression.
    struct Stack s;
    int x1,x2,r;
    
    for(int i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
            s.push(postfix[i]-'0');
        }else{//if it is an operator.
            x2=s.pop();
            x1=s.pop();

            switch(postfix[i]){
                case '+':
                    r=x1+x2;
                    s.push(r);
                    break;
                case '-':
                    r=x1-x2;
                    s.push(r);
                    break;
                case '*':
                    r=x1*x2;
                    s.push(r);
                    break;
                case '/':
                    r=x1/x2;
                    s.push(r);
                    break;
            }
        }
    }
    return s.pop();
}

int main(){
char* s="3*5+6/2-4";

cout<<evaluate(convert(s));
return 0;
}