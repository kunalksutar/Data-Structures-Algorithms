#include<iostream>
using namespace std;

struct Node{
    Node* prev;
    int data;
    Node* next;
} *head=NULL;

void create(int A[],int size){
    struct Node* temp;
    struct Node* itr;

    head= new Node;
    head->data=A[0];
    head->prev=NULL;
    head->next=NULL;
    itr = head;

    for(int i=1;i<size;i++){
        temp = new Node;//it is important to write this point here inside for loop.
        //since we want to create new node in heap every single loop.
        temp->data=A[i];
        temp->prev=itr;
        temp->next=NULL;
        itr->next=temp;
        itr=temp;
        }
}

void insert(struct Node* p,int index,int val){
    struct Node* temp = new Node;
    temp->data=val;
    
    if(index==1){//meaning it is being added at head.
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        head=temp;
    }else{//meaning anywhere else.
        struct Node* itr=head;
        for(int i=0;i<index-1;i++){
            itr=itr->next;//will land on the node just before we want to add the new node.
        }
        temp->next=itr->next;
        temp->prev=itr;
        itr->next=temp;
        itr->next->prev=temp;
    }
}

void Delete(struct Node* p,int index){
    int x;

    if(index==1){//if we want to delete head node.
        head=head->next;
        x=p->data;
        delete p;

        if(head!=NULL){//
            head->prev=NULL;
        }
    }else{//if anywhere else in the list.
        for(int i=0;i<index-1;i++){
            p=p->next;//will land exactly on the node we want to delete.
        }

        p->prev->next=p->next;
        if(p->next!=NULL){
            p->next->prev=p->prev;
        }

        x=p->data;
        delete p;
    }
}

void display(struct Node* p){
    cout<<"NULL--";
    while(p!=NULL){
        cout<<p->data<<"--";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

void reverse(struct Node* p){
    struct Node* temp;//to hold temporary data.
    while(p!=NULL){//swaping prev with next.
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;

        p=p->prev;//now in order to go front, we will have to access 'prev' instead of 'next'.
        if(p!=NULL && p->next==NULL){
            head=p;
        }
    }//meaning when this loop ends, p will be on a NULL pointer.
}

int main(){

int A[7]={23,5,65,72,63,74,57};
create(A,7);
display(head);

//insert(head,2,69);
//display(head);

reverse(head);
display(head);

return 0;
}