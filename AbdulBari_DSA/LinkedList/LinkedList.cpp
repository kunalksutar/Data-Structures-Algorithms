#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*head = NULL;//this is now a global variable.

void create(int A[],int size){
    struct Node* node;
    struct Node* last;
     
    head = new Node;//head is a pointer that will point to a node in heap.
    head->data = A[0];
    head->next = NULL;
    last = head;//since the linked list at this point is only made of 1 node.
    //it's head node and last node will point to the same node.

    for(int i=1;i<size;i++){
        node = new Node;//will create a new node inside heap.
        node->data = A[i];
        last->next = node;
        last = node;
        last->next = NULL;//this step is very important because if we don't write this...
        //it will by default set some garbage value, meaning point to some random location.
        //and will run infinitely.
    }

}

void display(struct Node* p){
    while(p!=NULL){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

void recurr_display(struct Node* p){
    if(p!=NULL){
        cout<<p->data<<"->";
        recurr_display(p->next);
    }
    else{
        cout<<"NULL"<<endl;
        return;
    }
}

int count(struct Node* p){
    if(p!=NULL){
        return count(p->next)+1;
    }else{
        return 0;
    }
}

int sum(struct Node* p){
    if(p!=NULL)return sum(p->next)+p->data;
    else return 0;
}

int max(struct Node* p){
int max=INT32_MIN;
    if(p!=NULL)max=p->data;
    
    while(p!=NULL){
        if(max<p->data)max = p->data;
        p=p->next;
    }return max;
}

int max_recurr(struct Node* p){
    int x;
    if(p==NULL){
        return INT32_MIN; 
    }
    x = max_recurr(p->next);
    return x > p->data ? x : p->data;

}

struct Node* LinearSearch(struct Node* p, int key){
    struct Node* q=NULL;//initialy this point to nothing, later it will follow p.
    while(p!=NULL){
        if(p->data == key){
            q->next = p->next;
            p->next=head;
            head=p;
            return p;
        }
        q=p;
        p=p->next;
    }
}

struct Node* reccur_LinearSearch(struct Node* p, int key){
    if(p==NULL){
        return NULL;
    }
    
    if(p->data == key){
        return p;
    }
    reccur_LinearSearch(p->next,key);
}

void insert(struct Node* p,int index, int val){
    struct Node* temp = new Node;//the new node we are trying to insert.
    temp->data = val;

    if(index==0){//meaning if we want to add at head.
        temp->next=head;
        head=temp;
        
    }else if(index>0){
        for(int i=0;i<index-1 && p;i++){
            p=p->next;//this will leave the pointer just before the node we want to add.
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void insertAtLast(struct Node* p,int val){
    struct Node* temp = new Node;
    temp->data = val;
    temp->next = NULL;

    if(head==NULL){
        head = temp;
    }
    struct Node* last = new Node;//this will get to the end of the list and add another node.
    last = head;
    while(last->next!=NULL){
        last=last->next;
    }
}

void insertsorted(struct Node* p,int val){
    struct Node* q = new Node;
    q=NULL;//tail node
    //and p will be a leading node.
    while(p->data < val && p){
        q=p;
        p=p->next;//this means at the end of this loop,'p' will land on the node which is
        //just greater than val. and q will be just less than. so we have to add a node in b/w.
    }

    struct Node* temp = new Node;
    temp->data = val;
    temp->next = p;
    q->next=temp;
}

void Delete(struct Node* p,int index){
    //NOTE: first node is considered to have index = 1.
    //so starting from 1,2,3....
    int x;//to store the deleted value.

    if(index==1){//meaning if we want to delete first element.
        struct Node* temp = head;
        head = head->next;
        x = temp->data;
        delete temp;
    }else{
        struct Node* q = NULL;//tailing node.
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;//will land on the 'to be deleted node'.
        }

        q->next = p->next;
        x = p->data;
        delete p;
    }
}

bool isSorted(struct Node* p){
    int x = INT32_MIN;
    while(p!=NULL){
        if(p->data < x){
            return false;
        }else{
            x = p->data;
            p=p->next;
        }
    }
    return true;
}

void removeDups(){
    struct Node* q=head;//tail node.
    struct Node* p;//leading node.
    p=head->next;

    while(p!=NULL){
        if(p->data!=q->data){
            q=p;
            p=p->next;
        }else{//if the elements are same.
            q->next = p->next;
            delete p;
            p=q->next;
        }
    }
}

void reverse_with_array(struct Node* p){
    int A[count(p)];
    int i=0;
    while(p!=NULL){
        A[i]=p->data;
        i++;
        p=p->next;
    }

    p=head;//again bringing 'p' to the head node.
    i--;//since for the last iter it will run out.

    while(p!=NULL){
        p->data = A[i];
        i--;//now we will decreament the iterator since we want coming back in reverse.
        p=p->next;
    }
}

void reverse_links(struct Node* p){
struct Node* r=NULL;//tail node.
struct Node* q=NULL;//middle node.
//and p is leading node.

while(p!=NULL){
    r=q;
    q=p;
    p=p->next;
    //till here we were only sliding the pointers by 1 unit ahead.
    q->next = r;//this is the important step where we reverse the link.
    }
    head = q;//read(red) as head will point whereever 'q' is pointing.
}

void reverse_recurr(struct Node* q,struct Node* p){
    if(p!=NULL){
        reverse_recurr(p,p->next);
        p->next = q;
    }else{
        head=q; 
    }
}

void concatinate(struct Node* first,struct Node* second){
    while(first->next!=NULL){
        first=first->next;//first will land on the last non-NULL node.
    }

    first->next = second;
}

struct Node* merge(struct Node* first,struct Node* second){
    struct Node* third=NULL;//we will return this as result.
    struct Node* itr=NULL;//this will do all the work of connecting.

    //initialization.
    if(first->data>second->data){
        third=second;
        itr=second;
        second=second->next;
        third->next=NULL;
    }else{
        third=first;
        itr=first;
        first=first->next;
        third->next=NULL;
    }//after this we won't play with the 'third' node at all, since it contains the head,
    //we will return later.

    while(first!=NULL && second!=NULL){
        if(first->data > second->data){
            itr->next = second;//connect the bridge.
            itr=second;//jump itr to the next node.
            second=second->next;//jump second to the next.
            itr->next=NULL;//break the bridge.
        }else{
            itr->next = first;//connect the bridge.
            itr=first;//jump itr to the next node.
            first=first->next;//jump second to the next.
            itr->next=NULL;//break the bridge.
        }
    }

    if(first!=NULL){
        itr->next=first;
    }
    if(second!=NULL){
        itr->next=second;
    }

    return third;
}

bool isLoop(struct Node* p){
    struct Node* fast=p;
    struct Node* slow=p;
    do{
        slow=slow->next;
        fast=fast->next;
        fast= fast!=NULL ? fast->next : NULL;
    }while(slow!=NULL && fast!=NULL && fast!=slow);

    return fast==slow ? true : false;
}

void display_loopedLinkedList(struct Node* p){
    static int flag = 0;
    if(p!=head || flag==0){
        flag=1;
        cout<<p->data<<"->";
        display_loopedLinkedList(p->next);
    }
    flag = 0;
}

int mid(struct Node* p){
    struct Node* fast = p;
    struct Node* slow = p;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next;
        if(fast->next==NULL){
            return slow->data;
        }
        slow=slow->next;
        if(fast!=NULL){
            fast=fast->next;
        }
    }
    return slow->data;
}

int main(){

int A[]={12,34,66,75,73,8};
create(A,6);
recurr_display(head);
//cout<<max(head)<<endl;

//LinearSearch(head,75);
//display(head);

insertsorted(head,69);
display(head);

Delete(head,2);
display(head);

//reverse_recurr(NULL,head);
display(head);

//cout<<isLoop(head);
cout<<mid(head);

return 0;
}