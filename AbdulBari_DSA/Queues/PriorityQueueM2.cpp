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
                cout<<"Stack is full.";
            }else if(front==rear){//meaning the queue is empty.
                Q[++rear]=val;
            }else{
                for(int i=front+1;i<rear+1;i++){
                    if(val>Q[i]){
                        for(int j=rear+1;j>i;j--){
                            Q[j]=Q[j-1];
                        }
                        Q[i]=val;
                        rear++;//at the end we will increament rear by 1.
                    //since a new element is added.
                    return;
                    }   
                }
                Q[++rear]=val; 
                return;
            }
        }

        int dequeue(){
            int x = -1;
            if(front==rear){
                cout<<"Queue is empty."<<endl;
            }else{//if not then pop.
                x=Q[rear--];
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
            return front==rear ? true : false;
        }

        bool isFull(){
            return rear==size-1 ? true : false;
        }

};

int main(){
    struct Queue q;
    q.enqueue(5);
    q.enqueue(33);
    q.enqueue(17);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(1);

    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;

}