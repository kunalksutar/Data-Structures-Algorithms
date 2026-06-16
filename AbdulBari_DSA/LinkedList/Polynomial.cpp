#include<iostream>
#include<math.h>
using namespace std;

struct Node{
    int coeff;
    int exp;
    struct Node* next;
} *head=NULL; 

void create(struct Node* p){
    int nums;
    cout<<"Enter number of terms :";
    cin>>nums;

    int coeff,exp;
    struct Node* temp;

    for(int i=0;i<nums;i++){
        cout<<"enter coeff and exp: ";
        cin>>coeff>>exp;

        temp = new Node;
        temp->coeff=coeff;
        temp->exp=exp;
        temp->next=NULL;

        if(p==NULL){
            p=temp;
        
        }else{
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=temp;
          
        }
    }
}

int evaluate(struct Node* p,int x){
    int result=0;
    cout<<bool(!p);
    while(p!=NULL){
        result=result+(p->coeff*pow(x,p->exp));
        cout<<p->coeff<<p->exp;
        p=p->next;
    }
    //return result;
}

void display(struct Node* p){
    while(p!=NULL){
        cout<<p->coeff<<"x"<<p->exp<<" + ";
        p=p->next;
    }
}

int main(){
    create(head);
    //display(head);
    //cout<<evaluate(head,5);
    cout<<(head==NULL);//PROBLEM IS HERE, HEAD IS NOT UPDATING ONLY.
    return 0;
}
