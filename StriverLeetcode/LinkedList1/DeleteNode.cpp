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

void deleteNode(ListNode*node){
    if(node->next==NULL)node=NULL;
    struct ListNode*p=node->next;
    struct ListNode*q=node;
    while(p->next!=NULL){
        q->val=p->val;
        q=p;p=p->next;
    }q->val=p->val;
    q->next=NULL;
    delete p;
}

int main(){
int n;cin>>n;
return 0;
}