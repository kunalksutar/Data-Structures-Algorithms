#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode*mergeTwoLists(ListNode*l1,ListNode*l2){
    if(l1==NULL)return l2;
    else if(l2==NULL)return l1;

    struct ListNode* head;
    if(l1->val>l2->val){
        head=l2;
        l2=l2->next;
    }else{
        head=l1;
        l1=l1->next;
    }
    struct ListNode* itr=head;

    while(l1!=NULL && l2!=NULL){
        if(l1->val>l2->val){
            itr->next=l2;
            itr=itr->next;
            l2=l2->next;
        }else{
            itr->next=l1;
            itr=itr->next;
            l1=l1->next;
        }
    }

    while(l1!=NULL){
        itr->next=l1;
        itr=l1;
        l1=l1->next;
    }
    while(l2!=NULL){
        itr->next=l2;
        itr=l2;
        l2=l2->next;
    }
    return head;
}

int main(){
int n;cin>>n;
return 0;
}