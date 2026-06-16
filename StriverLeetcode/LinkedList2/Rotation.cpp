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

ListNode*rotateRight(ListNode*head,int k){
    if(head==NULL||head->next==NULL)return head;
    int length=0;struct ListNode*p=head;
    while(p){length++;p=p->next;}p=head;
    k=k%length;
    if(k==0)return head;

    for(int i=0;i<length-k-1;i++)p=p->next;
    struct ListNode*tempRoot=head;
    head=p->next;p->next=NULL;p=head;
    while(p->next)p=p->next;
    p->next=tempRoot;
    return head;
}

int main(){
int n;cin>>n;
return 0;
}