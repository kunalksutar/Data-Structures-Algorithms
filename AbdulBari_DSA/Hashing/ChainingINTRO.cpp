#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*root=NULL;

int hashFunction(int key){return key%10;}

void insert(struct Node* H[],int key){
    int index=hashFunction(key);
    struct Node* temp;
    struct Node*p=H[index];
    struct Node*q=NULL;
    //p : lead node.
    //q : tail node. 
    temp=new Node;
    temp->data=key;

    if(H[index]==NULL){
        H[index]=new Node;
        H[index]->next=NULL;
        H[index]->data=key;
        return;
    }
    
    while(p!=NULL && p->data<key){q=p;p=p->next;}
    
    if(q==NULL){
        H[index]=temp;
        temp->next=p;
    }else{
        q->next=temp;
        temp->next=p;
    }
}

bool search(struct Node* H[],int key){
    int index=hashFunction(key);
    struct Node* p=H[index];
    while(p!=NULL){if(p->data==key)return true;else p=p->next;}
    return false;
}

int main(){
    struct Node* H[10];
    for(int i=0;i<10;i++)H[i]=NULL;//initially setting all pointers to null.

    insert(H,17);
    insert(H,7);
    insert(H,87);
    insert(H,67);

    cout<<search(H,67);//CODE NOT WORKING.
return 0;
}