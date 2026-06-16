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

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node*copyRandomList(Node*root){
    if(root==NULL)return NULL;
    unordered_map<Node*,Node*>m;
    struct Node* ans=new Node(root->val);
    struct Node* p=root;struct Node*q=ans;
    m[p]=q;
    p=p->next;
    while(p){
        struct Node*temp=new Node(p->val);
        q->next=temp;q=q->next;
        m[p]=q;p=p->next;
    }q=ans;p=root;

    while(q){
        if(p->random==NULL)q->random=NULL;
        else q->random=m[p->random];
        p=p->next;q=q->next;
    }return ans;
}

int main(){
int n;cin>>n;
return 0;
}