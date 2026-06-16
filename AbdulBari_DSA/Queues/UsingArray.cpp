#include<iostream>
using namespace std;

struct Queue{
    private:
        int size;
        int front;//deleting elements from fron or I should say left.
        int rear;//add elements from the back or I should say right.
        int *Q;//will later assign a array in heap.
    public: 
        Queue(){//constructor
            size=10;
            front=rear=-1;
            Q=new int[size];
        }

        Queue(int size){
            this->size=size;
            front=rear=-1;
            Q=new int[this->size];
        }

        void enqueue(int val){
            if(rear==size-1){
                cout<<"Queue is full."<<endl;
            }else{
                Q[++rear]=val;
            }
        }

        int dequeue(){
            int x;
            if(front==rear){
                cout<<"Queue is empty."<<endl;
                x=-1;
            }else{
                x=Q[++front];
            }
            return x;
        }

        void display(){
            if(front==rear){
                cout<<"Queue is empty."<<endl;
            }else{
                cout<<"FRONT-";
                
                for(int i=front+1;i<rear+1;i++){
                    cout<<Q[i]<<"-";
                }
                cout<<"REAR"<<endl;
            }   
        }

        bool isEmpty(){
            return front==rear;
        }

        bool isFull(){
            return rear==size-1;
        }

};

int main(){

struct Queue q(10);
q.enqueue(12);
q.enqueue(7);
q.enqueue(2);
q.enqueue(23);

q.display();
return 0;
}