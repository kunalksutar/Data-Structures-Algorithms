#include<iostream>
#include<cmath>
using namespace std;

struct Node{int data;struct Node* next;};
void display(int A[],int length){for(int i=0;i<length;i++)cout<<A[i]<<" ";cout<<endl;}
int max_val(int A[],int n){int max=A[0];for(int i=1;i<n;i++)if(A[i]>max)max=A[i];return max;}

void radixSort(int A[],int n){
    bool isSorted;
    int itr=0;
    do{
        Node* count[10];//notice we only 
        for(int i=0;i<10;i++)count[i]=NULL;//setting everything to null.

        isSorted=true;
        for(int i=0;i<n;i++){//In this part, we are just adding 
            
            int index=(A[i]/static_cast<int>(pow(10,itr)))%10;
            if(i>0 && A[i]<A[i-1])isSorted=false; 

            if(count[index]==NULL){//if the head node is null.
                count[index]=new Node;
                count[index]->data=A[i];
                count[index]->next=NULL;
                continue;
            }

            struct Node* p=count[index];
            while(p->next!=NULL)p=p->next;

            struct Node* temp=new Node;
            temp->data=A[i];
            temp->next=NULL;
            p->next=temp;
        }
        if(isSorted)return;
            
        int k=0;//through A.
        for(int i=0;i<10;i++){
            while(count[i]!=NULL){
                    A[k++]=count[i]->data;
                    struct Node* p=count[i];
                    count[i]=count[i]->next;
                    delete p;
                }
        }
        itr++;
    }while(!isSorted);      
}

int main(){
    int A[]={12,43,52,55,2,17,32,14,19};
    display(A,9);

    radixSort(A,9);

    display(A,9);
return 0;
}