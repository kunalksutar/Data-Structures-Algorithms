#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct BST{       
    public: 
        struct Node* root;
            BST(){
                root=NULL;
            }

            BST(int val){
                root=new Node;
                root->data=val;
                root->left=root->right=NULL;
            }
            
            void insert(int val){
                struct Node*temp;
                struct Node*tail=NULL;//tail node will follow p around.
                struct Node*p=root;

                if(p==NULL){//meaning there is no node present.
                    p=new Node;
                    p->data=val;
                    p->left=p->right=NULL;
                    root=p;
                    return;
                }

                while(p!=NULL){
                    tail=p;
                    if(p->data>val){
                        p=p->left;//we do not add it. Since a BST can not have same elements.
                    }else if(p->data<val){
                        p=p->right;
                    }else{//we do not add it. Since a BST can not have same elements.
                        return;
                    }
                }
                //meaning this portion below will be excuted only if p==NULL.
                //meaning the it has reached leaf node.
                temp=new Node;//allocating in heap.
                temp->data=val;
                temp->left=temp->right=NULL;

                if(tail->data>val){
                    tail->left=temp;
                }else{
                    tail->right=temp;
                }
            }

            struct Node* insert_recurr(struct Node* p,int val){
                
                struct Node* temp;

                if(root==NULL){
                    root=new Node;
                    root->data=val;
                    root->right=root->left=NULL;
                    return root;
                }

                if(p==NULL){
                    temp=new Node;
                    temp->data=val;
                    temp->right=temp->left=NULL;
                    return temp;
                }

                if(p->data>val){
                    p->left=insert_recurr(p->left,val);
                }else{
                    p->right=insert_recurr(p->right,val);
                }

            }

            struct Node* Search(int val){
                struct Node* p=root;

                while(p!=NULL){
                    if(p->data>val){
                        p=p->left;
                    }else if(p->data<val){
                        p=p->right;
                    }else{//meaning if they are equal.
                        return p;
                    }
                }
                //the below code will execute only when p==NULL,
                //meaning it reached the end of the tree(leaf node) but didn't find the element.
                return NULL;
            }

            struct Node* searchRecurr(struct Node* p,int val){
                
                if(p!=NULL){
                    if(p->data==val){
                        return p;
                    }else if(p->data>val){
                        return searchRecurr(p->left,val);
                    }else{
                        return searchRecurr(p->right,val);
                    }
                }else{//meaning if it reached the bottom of the tree(leaf node)
                    return NULL;
                }
            }

            struct Node* myFailedAttemptAtWritingDeleteFunction(struct Node* p,int val){
                struct Node* tail=NULL;//will tail the p node;
                int which_side=0;//if 0 means on left and...
                //if 1 then means on right of tail node.

                while(p!=NULL){
                    if(p->data==val){
                        break;
                    }else if(p->data>val){
                        tail=p;
                        p=p->left;
                        which_side=0;
                    }else{//meaning id p->data<val.
                        tail=p;
                        p=p->right;
                        which_side=1;
                    }
                }//at the end when this loop breaks...
                //'p' will point on the desired node and tail will point just before it.

                if(p==NULL){
                    cout<<"No such node found."<<endl;
                    return NULL;
                }else if(p!=NULL && tail!=NULL){//if there exists such element and p landed on the desired node...
                //and the p is NOT equal to root node itself.
                    if(p->left==NULL && p->right==NULL){//is a leaf node.
                    //other way to say is if it has no children, then....
                    //we simply delete.
                        if(which_side==0){//meaning the node is to the left of the tail node.
                            tail->left==NULL;
                            return p;//we don't physically delete but just disconnect it from..
                            //the BST.
                        }else{//meaning the node is to the right of the tail node.
                            tail->right==NULL;
                            return p;//we don't physically delete but just disconnect it from..
                            //the BST.
                        }
                    }else if(p->left==NULL ^ p->right==NULL){//either this is true or...
                    //that is true. Or should I say...
                    //the condition will true only when exactly one of them is true.
                    //meaning when it has exactly one child.

                        if(p->left!=NULL){//if it has a left child then.
                            if(which_side==0){
                                tail->left=p->left;
                                return p;
                            }else{
                                tail->right=p->left;
                                return p;
                            }
                        }else{//meaning if it has a right child.
                            if(which_side==0){
                                tail->left=p->right;
                                return p;
                            }else{
                                tail->right=p->right;
                                return p;
                            }
                        }
                    }else{//if it has both the childs.
                    //for now we will only focus on the left predeseccor.

                        struct Node* leftpred=p->left;//we are writing this statement...
                        //very confidently as if we know that p->left is not NULL...
                        //well we are 100% that is the case beacuse if it was NULL...
                        //this case would not even open.
                        while(leftpred->right!=NULL){
                            leftpred=leftpred->right;
                        }
                        //now leftpred will pointing at the left predecessor.
                        
                        if(which_side==0){
                            tail->left=leftpred;
                            myFailedAttemptAtWritingDeleteFunction(root,leftpred->data);
                            leftpred->right=p->right;
                            leftpred->left=p->left;
                            return p;
                        }else{
                            tail->right=leftpred;
                            myFailedAttemptAtWritingDeleteFunction(root,leftpred->data);
                            leftpred->right=p->right;
                            leftpred->left=p->left;
                            return p;
                        }
                    }
                }else if(p!=NULL && tail==NULL){//when the node to be deleted is the root node itself.
                //I could also write the above if condition as (p==root), both are same.


                }
            }

            
            int height(struct Node* p){
                int x,y;
                if(p!=NULL){
                    x=height(p->left);
                    y=height(p->right);
                    if(x>y){
                        return x+1;//whichever has the greater depth.
                    }else{
                        return y+1;
                    }
                }else{
                    return 0;
                }
            }

            struct Node* InPred(struct Node* p){
                while(p->right!=NULL){
                    p=p->right;
                }
                return p;
            }

            struct Node* InSucc(struct Node* p){
                while(p->left!=NULL){
                    p=p->left;
                }
                return p;
            }

            struct Node* Delete(struct Node* p,int val){
                if(p==NULL){
                    return NULL;
                }
                if(p->left==NULL && p->right==NULL){//for leaf node.
                //we physically delete node only when it is a leaf node.
                    p=NULL;
                    delete p;
                    return NULL;
                }
                
                if(p->data>val){
                    p->left=Delete(p->left,val);
                }else if(p->data<val){
                    p->right=Delete(p->right,val);
                }else{//meaning if we have found the node to be delteted.
                    struct Node* temp;
                    if(height(p->left)>height(p->right)){//meaning if there are more...
                    //elements to the right of tree.
                        temp=InPred(p->left);
                        p->data=temp->data;
                        p->left=Delete(p->left,temp->data);
                    }else{
                        temp=InSucc(p->right);
                        p->data=temp->data;
                        p->right=Delete(p->right,temp->data);
                    }
                }
                return p;//this code will be executed only when the node which...
                //p is on is not NULL;
                //what do we mean by return this p ? 
                //this will return the address of the updated subtree.
            }

            void preOrder(struct Node* p){
                if(p!=NULL){
                    cout<<p->data<<" ";
                    preOrder(p->left);
                    preOrder(p->right);
                }
            }

            void inOrder(struct Node* p){
                if(p!=NULL){
                    inOrder(p->left);
                    cout<<p->data<<" ";
                    inOrder(p->right);
                }
            }

            int count(struct Node* p){
                if(p!=NULL){
                    return count(p->left)+count(p->right)+1;//count that node for plus 1.
                }else{
                    return 0;
                }
            }

            
};

int main(){
    cout<<"hello"<<endl;
    struct BST tree1;/*
    tree1.insert(12);
    tree1.insert(3);
    tree1.insert(55);
    tree1.insert(34);
    tree1.insert(1);

    tree1.insert_recurr(tree1.root,14);
    tree1.insert_recurr(tree1.root,13);
    tree1.preOrder(tree1.root);
    cout<<endl;
    tree1.inOrder(tree1.root);
    cout<<endl;

    cout<<tree1.count(tree1.root);tree1.insert_recurr(tree1.root,14);

    cout<<endl;

    cout<<tree1.height(tree1.root);
    cout<<endl;

    cout<<tree1.searchRecurr(tree1.root,69);
    cout<<endl;
    */

    tree1.insert(30);
    tree1.insert(10);
    tree1.insert(50);
    
    
    tree1.inOrder(tree1.root);
    cout<<endl;
    tree1.Delete(tree1.root,10);

    tree1.inOrder(tree1.root);
    cout<<endl;

return 0;
}