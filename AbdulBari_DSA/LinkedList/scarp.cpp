#include<iostream>
using namespace std;

struct Node{
    int coeff;
    int exp;
    struct Node* next;
} *head=NULL;

void func(struct Node* p){
    cout<<(p!=NULL);
}

int main(){
    func(head);
    //cout<<(head==NULL);
    return 0;
}