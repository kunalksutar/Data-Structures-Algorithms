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

struct Node{
	int data;
	struct Node*next;
	struct Node*bottom;
    Node(int x){data=x;next=NULL;bottom=NULL;}
};

Node*flatten(Node*root){
	struct Node*p=root;
	
}


int main(){
int n;cin>>n;
return 0;
}