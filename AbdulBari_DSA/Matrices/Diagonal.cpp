#include<iostream>
using namespace std;

struct Diagonal{
    private: 
        int size;
        int *A;//dinamicly create an array.
    public:
        Diagonal(int size){
            this->size = size;
            A = new int[size];
        }

        void set(int i,int j,int val);
        int get(int i,int j);
        void display();
        ~Diagonal(){
            delete []A;
        }


};

void Diagonal::set(int i,int j,int val){
    if(i==j){
        A[i-1]=val;
    }
}

int Diagonal::get(int i,int j){
    if(i==j){
        return A[i-1];
    }else{
        return 0;
    }
}

void Diagonal::display(){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            if(i==j){
                cout<<A[i]<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}


int main(){

struct Diagonal mat1(4);
    
    mat1.set(1,1,15);
    mat1.set(2,2,20);
    mat1.set(3,3,25);
    mat1.set(4,4,30);

    mat1.display();

    return 0;
}