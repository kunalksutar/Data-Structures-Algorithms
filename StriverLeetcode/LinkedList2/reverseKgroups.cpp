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

ListNode*reverseKGroup(ListNode*head,int k){
    if(k==1)return head;

    int length=0;struct ListNode*p=head;
    while(p){length++;p=p->next;}

    struct ListNode*r=NULL;
    struct ListNode*q=NULL;
    struct ListNode*first=NULL;
    bool firstLoop=true;
    for(int i=0;i<length/k;i++){
        for(int j=0;j<k;j++){
            r=q;q=p;p=p->next;
            q->next=r;
        }
        if(firstLoop){
            first=head;head->next=p;
            head=q;
            //now setting up for the next loop.
            r=first;q=first;
            firstLoop=false;
        }else{
            first->next->next=p;
            first->next=q;
            for(int i=0;i<k;i++)first=first->next;
            r=first;q=first;
        }
    }return head;
}

int main(){
int n;cin>>n;
return 0;
}