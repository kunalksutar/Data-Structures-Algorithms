#include<iostream>
using namespace std;

struct Node{
    int col;
    int data;
    struct Node* next;
};

struct Sparse{
    int m;//number of rows
    int n;//columns
    struct Node** A;//this is a pointer to a matrix that will hold the list heads to linked list
    //the first star indicates that A is a Node* data type.
    //the second star indicates that A is a pointer to an array that will hold datatype of
    //Node*
};

void create(struct Sparse* s){

    //NOTE: The row and column number is starting from 0.
    int m,n;
    cout<<"Enter the dimensions : ";
    cin>>m>>n;

    s->m=m; s->n=n;//now that we know the number of nodes, we will create the array.
    s->A= new Node*[m];//create an array in heap of m dimensions.

    //setting all nodes to NULL initially.
    for(int i=0;i<m;i++){
        s->A[i]=NULL;
    }

    int nums;
    cout<<"Enter number of non-zero elements : ";
    cin>>nums;

    
    int row,col,data;

    struct Node* temp;//node we want to add.
    struct Node* itr;//node that will edit our row.

    for(int i=0;i<nums;i++){

        cout<<"Enter the row number, column number & value : ";
        
        temp=new Node;

        cin>>row>>col>>data;
        temp->data=data;
        temp->col=col;
        temp->next=NULL;

        itr=s->A[row];
        if(itr==NULL){//if there is no head.
            itr=temp;
            
        }else{
            while(itr->next!=NULL){
                itr=itr->next;
            }
            itr->next=temp;
        }
    }

}

void display(struct Sparse* s){
    struct Node* p;
    cout<<endl<<"Sparse matrix : "<<endl;
    
    for(int i=0;i<s->m;i++){
        p=s->A[i];//will point to the head node.
       
        for(int j=0;j<s->n;j++){
            if(p!=NULL && p->col==j){//code  NOT working because of this line of code.
                cout<<p->data<<" ";
                p=p->next;
                cout<<"k";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }

}

int main(){

struct Sparse s;
create(&s);
display(&s);

return 0;
}