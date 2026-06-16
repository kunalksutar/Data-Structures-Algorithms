#include <iostream>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Stack{
    private:
        int size;
        int top;
        struct Node **s;//CHANGED HERE!
    public:
        Stack(){//constructor
            top=-1;
            size=20;
            s=new Node*[size];
        }

        void push(Node* p){
            if(top==size-1){//meaning if the stack is filled to the top.
                cout<<"Stack-Overflow";
            }else{
                s[++top]=p;
            }
        }

        Node* pop(){
            Node* x=NULL;
            if(top==-1){
                cout<<"Stack-Underflow : ";
            }else{
                x=s[top--];
            }
            return x;
        }

        struct Node* peek(int pos){
            struct Node* x=NULL;
            if(top-pos+1<0){
                cout<<"Invalid postion : ";
            }else{
                x=s[top-pos+1];
            }
            return x;
        }

        Node* stackTop(){
            if(top==-1){
                return NULL;
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


struct Stack_int{//NEW STACK THAT WILL STORE INT DATATPYE.
                //Had to modifiy it for using it in post order traversal.
    private:
        int size;
        int top;
        int *s;//CHNANGED HERE!
    public:
        Stack_int(){//constructor
            top=-1;
            size=20;
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


struct Queue{//implemented using Array.
    private:
        int size;
        int front; // deleting elements from fron or I should say left.
        int rear;  // add elements from the back or I should say right.
        struct Node **Q;  // CHANGED HERE !
        // since we want to store pointers and we store them in a array.
        // Q is a pointer to an array that will store Node* data type.
    public:
        Queue(){ // constructor
            size=10;
            front=rear=-1;
            Q=new Node*[size];
        }

        Queue(int size){
            this->size=size;
            front=rear=-1;
            Q=new Node*[this->size];
        }

        void enqueue(Node *p){ // CHANGED HERE! input will be of pointer type.
            if(rear==size-1){
                cout<<"Queue is full."<<endl;
            }else{
                Q[++rear]=p;
            }
        }

        Node *dequeue(){// CHNAGED HERE!
            Node *x; // CHANGED HERE!
            if (front==rear){
                cout<<"Queue is empty."<<endl;
                x=NULL;
            }else{
                x=Q[++front];
            }
            return x;
        }

        void display(){
            if (front == rear){
                cout << "Queue is empty." << endl;
            }
            else{
                cout << "FRONT-";
                for (int i = front + 1; i < rear + 1; i++){
                    cout << Q[i] << "-";
                }
                cout << "REAR" << endl;
            }
        }

        bool isEmpty(){
            return front==rear;
        }

        bool isFull(){
            return rear==size-1;
        }
};

struct Tree{
public:
    struct Node *root;
    Tree(){
        root = NULL;
    }
    
    void createTree(){
        struct Node* p;//this will be our builder.
        struct Node* temp;//this will be the new node added each time.
        struct Queue q(100);//setting the array size to 100

        int val;
        cout<<"Enter root node : ";
        cin>>val;
        
        //we will update the new node
        root = new Node;//since when initialized it would be NULL.
        //so we first allocate a memory in heap.
        root->data=val;
        root->lchild=root->rchild=NULL;

        q.enqueue(root);

        while(!q.isEmpty()){
            p=q.dequeue();
            
            cout<<"Enter left child of "<<p->data<<" : ";
            cin>>val;

            if(val!=-1){//if we enter -1, then we assume that there is no left node.
            //so we simply do nothing in that case.

            temp = new Node;
            temp->data=val;
            temp->lchild=temp->rchild=NULL;
            p->lchild=temp;
            q.enqueue(temp);
            }

            cout<<"Enter right child of "<<p->data<<" : ";
            cin>>val;

            if(val!=-1){//if we enter -1, then we assume that there is no right node.
            //so we simply do nothing in that case.

            temp = new Node;
            temp->data=val;
            temp->lchild=temp->rchild=NULL;
            p->rchild=temp;
            q.enqueue(temp);
            }
        }
    }

    void preOrder(){
        struct Stack s;
        struct Node* p=root;

        while(p!=NULL || !s.isEmpty()){
            if(p!=NULL){
                cout<<p->data<<" ";
                s.push(p);
                p=p->lchild;
            }else{//when reached null we want to access the previous node.
            //which will be at the top of the stack. So we pop it.
                p=s.pop();
                p=p->rchild;
            }
        }
    }

    void inOrder(){
        struct Node* p=root;
        struct Stack s;

        while(p!=NULL || !s.isEmpty()){
            if(p!=NULL){
                s.push(p);
                p=p->lchild;
            }else{//when reached null we want to access the previous node.
            //which will be at the top of the stack. So we pop it and print for inorder traversal.
                
            }
        }
    }
/*
    void postOrder(struct Node* p){
        struct Stack_int s;
        long int temp;

        while(p!=NULL || !s.isEmpty()){
            if(p!=NULL){
                s.push(p);
                p=p->lchild;
            }else{//if reached NULL from left side.
                temp=s.pop();
                if(temp>0){
                    s.push(-temp);
                
                }
            }
        }
    }

*/
};


int main(){
    struct Tree t; 
    t.createTree();

    t.inOrder();
    cout<<endl;

    t.preOrder();
return 0;
}