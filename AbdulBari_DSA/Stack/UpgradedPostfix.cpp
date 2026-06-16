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
    if(x=='+' || x=='-' || x=='*' || x=='/'|| x=='^'|| x=='('|| x==')'){
        return 0;
    }else{
        return 1;
    }
}

int inStackPre(char x){
    if(x=='+'||x=='-'){
        return 2;
    }else if(x=='*'||x=='/'){
        return 4;
    }else  if(x=='^'){
        return 5;
    }else  if(x=='('){
        return 0;
    }else{
        return -1;//for the questionmark at ')'
    }
}

int outStackPre(char x){
    if(x=='+'||x=='-'){
        return 1;
    }else if(x=='*'||x=='/'){
        return 3;
    }else  if(x=='^'){
        return 6;
    }else  if(x=='('){
        return 7;
    }else if(x==')'){
        return 0;//for the questionmark at ')'
    }
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
            if(outStackPre(infix[i])>inStackPre(s.stackTop())){
                s.push(infix[i++]);
            }else{//meaning when the presidence is equal or less.
            //we pop.
                if(s.stackTop()=='('||s.stackTop()==')'){
                    s.pop();//then we only pop and not add brackets in postfix.
                }else{
                    postfix[j++]=s.pop();
                }
            }
        }
    }

    while(!s.isEmpty()){
        if(s.stackTop()=='('||s.stackTop()==')'){
                    s.pop();//then we only pop and not add brackets in postfix.
                }else{
                    postfix[j++]=s.pop();
                }
        }

    postfix[j]='\0';
    return postfix;

}

int main(){
char* s="a+b*c-d/e";
char* t="((a+b)*c)-d^e^f";


cout<<convert(t);
return 0;
} 