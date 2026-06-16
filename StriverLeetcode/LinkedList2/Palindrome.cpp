#include<cstdlib>
#include<iostream>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<list>
#include<deque>
#include<array>
#include<cassert>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode*reverseList(ListNode*head){
    struct ListNode*r=NULL;
    struct ListNode*p=NULL;
    struct ListNode*q=head;

    while(q){
        r=p;p=q;q=q->next;
        p->next=r;
    }return p;
}

bool isPalindrome(ListNode*head){
    if(head==NULL||head->next==NULL)return head;
    //we will reverse the second half.
    struct ListNode*p=head;
    int length;while(p){p=p->next;length++;}
    p=head;for(int i=0;i<length/2;i++)p=p->next;
    reverseList(p);
    struct ListNode*q=head;
    for(int i=0;i<(length/2)-1;i++)if(q->val!=p->val)return false;
    return true;
}

int main(){
int n;cin>>n;
return 0;
}