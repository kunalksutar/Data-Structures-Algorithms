#include<iostream>
using namespace std;

struct Queue{//Circular Queue, but we keep the name same only.
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
            //for that we will first have to check if the queue is full or not.
            if((rear+1)%size==front){//if front is just next to rear, then we say...
            //the queue is full.
                cout<<"Queue is full."<<endl;
            }else{//when there is space left (meaning not full)
                rear=(rear+1)%size;//first will will increament rear.
                Q[rear]=val;
            }
        }

        int dequeue(){
            int x = -1;
            if(front==rear){//meaning if the queue is empty.
                cout<<"Queue is empty."<<endl;
            }else{//meaning if there are elements to delete.
                front=(front+1)%size;//increamenting front.
                //to write the above, think of when the front is at the last element of array.
                //in order to toggle to first, we increase it and then take mod.
                x=Q[front];
            }
            return x;
        }

        void display(){
            if(front==rear){
                cout<<"Queue is empty."<<endl;
            }else{
                cout<<"FRONT-";
                
                int i=front+1;
                while(i!=rear+1){
                    cout<<Q[i]<<"-";
                    i=(i+1)%size;//increamenting i
                }
                cout<<"REAR"<<endl;
            }   
        }

        bool isEmpty(){
            return front==rear ? true : false;
        }

        bool isFull(){
            return (rear+1)%size==front ? true : false;
        }

};

int main(){

return 0;
}
