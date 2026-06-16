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
            int x = -1;
            if(front==rear){
                cout<<"Queue is empty."<<endl;
            }else{
                int min=Q[front+1];
                int index=front+1;//will hold index of the minimum element.
                for(int i=front+1;i<rear+1;i++){
                    if(Q[i]<min){
                        min=Q[i];
                        index=i;
                    }
                }//at the end, index will hold the index of the minimum element.
                for(int i=index;i<rear;i++){
                    Q[i]=Q[i+1];
                }
                rear--;
                return min;
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