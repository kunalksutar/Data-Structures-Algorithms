#include<iostream>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    void findpath(struct TreeNode*root,struct TreeNode*target,deque<struct TreeNode*>&Q){
        if(root==NULL)return;
        Q.push_back(root);
        if(root==target)return;

        findpath(root->left,target,Q);
        findpath(root->right,target,Q);
        Q.pop_back();
    }

    TreeNode*lowestCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==NULL)return root;
        deque<struct TreeNode*>Q1,Q2;
        //finding the path till the node p.
        findpath(root,p,Q1);
        findpath(root,q,Q2);

        struct TreeNode*ans=root;
        while(!Q1.empty()&&!Q2.empty()){
            if(Q1.front()==Q2.front()){
                ans=Q1.front();
                Q1.pop_front();
                Q2.pop_front();
            }else break;
        }return ans;
    }
};

int main(){


return 0;
}