#include <iostream>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{//implemented using Array.
    private:
        int size;
        int front; // deleting elements from fron or I should say left.
        int rear;  // add elements from the back or I should say right.
        Node **Q;  // CHANGED HERE !
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

    void preOrder(struct Node* p){
        
        if(p!=NULL){
            preOrder(p->lchild);
            preOrder(p->rchild);
            cout<<p->data<<" ";
        }
    }

    void inOrder(struct Node* p){
        
        if(p!=NULL){
            inOrder(p->lchild);
            cout<<p->data<<" ";
            inOrder(p->rchild);
        }
    }

    void postOrder(struct Node* p){
        
        if(p!=NULL){
            cout<<p->data<<" ";
            postOrder(p->lchild);
            postOrder(p->rchild);
            
        }
    }

    void inLevel(){
        struct Queue q;
        struct Node* p=root;
        
        q.enqueue(p);
        cout<<p->data<<" ";

        while(!q.isEmpty()){
            p=q.dequeue();

            if(p->lchild!=NULL){
                cout<<p->lchild->data<<" ";
                q.enqueue(p->lchild);
            }
            if(p->rchild!=NULL){
                cout<<p->rchild->data<<" ";
                q.enqueue(p->rchild);
            }
        }
    }

    int count(struct Node* p){
        if(p!=NULL){
            return count(p->lchild)+count(p->rchild)+1;
        }else{
            return 0;//meaning when it has reached the leaf node.
        }
    }

    int height(struct Node* p){
        if(p!=NULL){
            int x=height(p->lchild);
            int y=height(p->rchild);

            if(x>y){
                return x+1;
            }else{
                return y+1;
            }
        }
        return 0;//this will be excecuted only when p is NULL, meaning reached leaf node.
    }
};


int main(){
    struct Tree t; 
    t.createTree();

    t.preOrder(t.root);
    cout<<endl;

    t.inOrder(t.root);
    cout<<endl;

    t.postOrder(t.root);
    cout<<endl;

    t.inLevel();
    cout<<endl;

return 0;
}