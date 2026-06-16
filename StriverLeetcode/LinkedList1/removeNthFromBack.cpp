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

ListNode*removeNthFromEnd(ListNode*head,int n){
    struct ListNode*temp=new ListNode();//we have to do this for edge case.
    temp->next=head;
    struct ListNode*fast=temp;
    struct ListNode*slow=temp;
    for(int i=0;i<n;i++)fast=fast->next;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }slow->next=slow->next->next;
    return temp->next;
}

int main(){
int n;cin>>n;
return 0;
}