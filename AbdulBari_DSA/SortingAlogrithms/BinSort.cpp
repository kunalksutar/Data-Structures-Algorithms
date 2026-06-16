#include<iostream>
using namespace std;

struct Node{int data;struct Node* next;};
void display(int A[],int length){for(int i=0;i<length;i++)cout<<A[i]<<" ";cout<<endl;}
int max_val(int A[],int n){int max=A[0];for(int i=1;i<n;i++)if(A[i]>max)max=A[i];return max;}

int binSort(int A[],int n){
    int max=max_val(A,n);
    Node** count= new Node*[max+1];

    for(int i=0;i<max+1;i++)count[i]=NULL;//setting everything to null.

    for(int i=0;i<n;i++){
        struct Node* p=count[A[i]];

        if(count[A[i]]==NULL){//if the head node is null.
            count[A[i]]=new Node;
            count[A[i]]->data=A[i];
            count[A[i]]->next=NULL;
            continue;
        }

        while(p->next!=NULL)p=p->next;

        struct Node* temp=new Node;
        temp->data=A[i];
        temp->next=NULL;
        p->next=temp;
        cout<<"this"<<endl;
    }
    
    int i=0;//through the count array.
    int k=0;//through A.
    while(i<max+1){
        if(count[i]==NULL)i++;
        else{
            while(count[i]!=NULL){
                A[k++]=count[i]->data;
                count[i]=count[i]->next;    
            }
        }
    }
}

int main(){
    int A[]={12,43,52,55,2,17,32,14,19};
    display(A,9);

    binSort(A,9);

    display(A,9);
return 0;
}