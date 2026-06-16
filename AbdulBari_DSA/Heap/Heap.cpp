#include<iostream>
using namespace std;

struct maxHeap{//Max heap
    public:
        int *A;
        int size;//total size of Array allocted.
        int length;//number of elements present inside heap.

        maxHeap(){
            size=20;
            A=new int[size];
            length=0;
        }

        maxHeap(int root_val){
            size=20;
            A=new int[size];
            A[0]=root_val;
            length=1;
        }

        maxHeap(int root_val,int size){
            this->size=size;
            A=new int[size];
            A[0]=root_val;
            length=1;
        }

        void swap(int &x,int &y){
            int temp=x;x=y;y=temp;
        }

        void insert(int val){
            int i=++length;//keep the indexing goes as follows : {1,2,3,4,5,6}
            //but in array they are located as : {0,1,2,3,4,5}
            //we assume range of i as : {1,2,3,4,5,6} 
            while(i>1 && val>A[(i/2)-1]){
                A[i-1]=A[(i/2)-1];
                i=i/2;
            }
            A[i-1]=val;//if the while loop didn't execute at all, we will add val to the last
            //element.
        }

        int Delete(){//since in heap we can only delete the highest number for max heap.
            //we don't take in any arguements.
            int x=A[0],i,j;
            A[0]=A[(length--)-1];//bringing the last number to first one.
            //at the same time decrementing length by 1 here itself.
            i=1;j=2*i;//REMINDER: i follows the following indexing : {1,2,3,...}
            //hencing starting from i=1; when putting it inside the array we use -1.
            
            //j points on the 1st child node and j+1 on the 2nd child.
            while(j<length+1){
                if(A[j]>A[j-1]){
                    j=j+1;//this if statement will end up on the index of the child node...
                    //which is max.
                }
                if(A[j-1]>A[i-1]){
                    swap(A[j-1],A[i-1]);
                    i=j;//i will jump onto it's children
                    j=j*2;//j will jump onto the new children.
                    //we could right this as j=2*i, same thing.
                }else{
                    break;//this is important point here to break.
                    //if the element is greater than the max on, then we must stop the...
                    //loop imideatly since, there is no point in looking further.
                    //the number has found it's new place. End of story.
                }
            }
            return x;
        }

        void displayLvl(){
            if(length==0){cout<<"Heap is empty."<<endl;return;}
            for(int i=0;i<length;i++)cout<<A[i]<<" ";
            cout<<endl;
        }

        ~maxHeap(){
            delete []A;
        }
};

void heapSort(int A[],int n){//n:number of elements
    struct maxHeap h;
    for(int i=0;i<n;i++)h.insert(A[i]);//first adding all elements in heap.
    for(int i=0;i<n;i++){
        A[n-1-i]=h.Delete();
    }
    h.~maxHeap();
}

void displayArray(int A[],int n){
    for(int i=0;i<n;i++)cout<<A[i]<<" ";
    cout<<endl;
}

int main(){

    struct maxHeap h(10);
    h.insert(12);
    h.insert(1);
    h.insert(33);
    h.insert(3);
    h.insert(8);
    h.insert(39);

    h.displayLvl();

    h.Delete();
    h.displayLvl();

    h.Delete();
    h.displayLvl();

    h.Delete();
    h.displayLvl();

    h.Delete();
    h.displayLvl();

    h.Delete();
    h.displayLvl();

    h.Delete();
    h.displayLvl();

    h.Delete();
    h.displayLvl();

    h.~maxHeap();

    int A[]={23,54,6,1,44,7,17,12,11,46,34};//creating a array of random numbers.
    heapSort(A,11);
    displayArray(A,11);


return 0;
}