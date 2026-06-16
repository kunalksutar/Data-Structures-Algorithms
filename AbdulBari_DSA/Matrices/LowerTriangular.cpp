#include<iostream>
using namespace std;

struct LowerMatrix{
    private: 
        int size;
        int *A;//dinamicly create an array.
    public:
        LowerMatrix(int size){
            this->size = size;
            A = new int[((size*size)+size)/2];
        }

        void set(int i,int j,int val);
        int get(int i,int j);
        void display();
        ~LowerMatrix(){
            delete []A;
        }


};

void LowerMatrix::set(int i,int j,int val){
    if(i>=j){
        A[(((i*i)-i)/2)+j-1]=val;
    }
}

int LowerMatrix::get(int i,int j){
    if(i>=j){
        return A[(((i*i)-i)/2)+j-1];
    }else{
        return 0;
    }
}

void LowerMatrix::display(){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            if(i>=j){
                cout<<A[(((i*i)-i)/2)+j-1]<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}


int main(){
int size = 4;
struct LowerMatrix mat1(size);
    
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            cout<<"enter an element : ";
            int element;
            cin>>element;
            mat1.set(i,j,element);
        }
    }

    mat1.display();

    return 0;
}