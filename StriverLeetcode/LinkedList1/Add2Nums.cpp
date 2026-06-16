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



ListNode*addTwoNumbers(ListNode*l1,ListNode*l2){
    int carry=(l1->val+l2->val)/10,sum=(l1->val+l2->val)%10;
    struct ListNode*head=new ListNode(sum%10);
    l1=l1->next;l2=l2->next;
    struct ListNode*itr=head;
    while(l1&&l2){
        sum=l1->val+l2->val;
        struct ListNode*temp=new ListNode((sum+carry)%10);
        itr->next=temp;
        itr=temp;
        carry=sum/10;
        l1=l1->next;l2=l2->next;
    }

    while(l1){
        sum=l1->val+carry;
        struct ListNode*temp=new ListNode(sum%10);
        itr->next=temp;
        itr=temp;
        carry=sum/10;
        l1=l1->next;
    }
    while(l2){
        sum=l2->val+carry;
        struct ListNode*temp=new ListNode(sum%10);
        itr->next=temp;
        itr=temp;
        carry=sum/10;
        l2=l2->next;
    }
    if(carry!=0){
        struct ListNode*temp=new ListNode(1);
        itr->next=temp;
    }return head;
}

int main(){
int n;cin>>n;
return 0;
}