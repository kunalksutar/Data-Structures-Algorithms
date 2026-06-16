#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    private:
        struct Node* front;
        struct Node* rear;
    public: 
        Queue(){front=rear=NULL;}

        void enqueue(int val){
            struct Node* temp = new Node;
            if(temp==NULL){//when the heap is full.
                cout<<"Queue is full."<<endl;
            }else{
                temp->data=val;
                temp->next=NULL;

                rear->next=temp;
                rear=temp;
            }
        }

        int dequeue(){
            int x = -1;
            if(front==NULL){
                cout<<"Queue is empty."<<endl;
            }else{
                struct Node* temp=front;
                front=front->next;
                x=temp->data;
                delete temp;
            }
            return x;
        }

        bool isEmpty(){
            return front==NULL ? true : false;
        }

        bool isFull(){
            struct Node* temp = new Node;
            return temp==NULL ? true : false;
        }
};

int main(){

return 0;
}