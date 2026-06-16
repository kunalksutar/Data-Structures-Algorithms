#include<iostream>
using namespace std;

struct Node{
    int data;
    int height;//we will maintain height of every node,
    //instead of calling height function everytime like a lunatic.
    struct Node* left;
    struct Node* right;
};

struct AVL{
    public: 
        struct Node* root;
        AVL(){
            root=NULL;
        }
        AVL(int val){
            root->data=val;
            root->height=1;
            root->left=root->right=NULL;
        }

        int NodeHeight(struct Node* p){//will return the height of the subtree(from the bottom)
        //or the root node p;
            if(p!=NULL){
                int hl=NodeHeight(p->left);//height of left subtree.
                int hr=NodeHeight(p->right);//right subtree.
                if(hl>hr){
                    return hl+1;
                }else{
                    return hr+1;
                }
            }
            return 0;
        }

        int balanceFactor(struct Node* p){
            if(p!=NULL){
                return NodeHeight(p->left)-NodeHeight(p->right);
            }
        }

        struct Node* LRRotation(struct Node* p){
            struct Node* pl=p->left;
            struct Node* plr=p->left->right;

                pl->right=p;
                p->left=plr;
                
                //now that we have made the correct changes, we will update their new heights.
                pl->height=NodeHeight(pl);
                p->height=NodeHeight(p);

                    if(p==root){//if in case the Node p, happened to be the Root of the tree.
                    //we will have to change the root of the tree.
                        root=pl;
                    }

                return pl;//we return pl instead of p, since this is our new node.
        }
        struct Node* LLRotation(struct Node* p){
            struct Node* pl=p->left;

                p->left=pl->right;
                pl->right=p;

                    if(p==root){
                        root=pl;
                    }

                pl->height=NodeHeight(pl);
                p->height=NodeHeight(p);

                return pl;
            
        }
        struct Node* RRRotation(struct Node* p){
            struct Node* pr=p->right;

                p->right=pr->left;
                pr->left=p;

                    if(p==root){
                        root=pr; 
                    }

                pr->height=NodeHeight(pr);
                p->height=NodeHeight(p);

                return pr;           
            }
        struct Node* RLRotation(struct Node* p){
            struct Node* pr=p->right;
            struct Node* prl=p->right->left;

                pr->left=p;
                p->right=prl;

                p->height=NodeHeight(p);
                pr->height=NodeHeight(pr);

                    if(p==root){
                        root=pr;
                    }

                return pr;
        }

        struct Node* insert(struct Node* p,int val){
            struct Node* temp;

                if(p==NULL){
                    temp=new Node;
                    temp->data=val;
                    temp->height=1;
                    temp->left=temp->right=NULL;

                    return temp;
                }

                if(p->data==val){
                    return NULL;
                }else if(p->data>val){
                    p->left=insert(p->left,val);
                }else{
                    p->right=insert(p->right,val);
                }
            p->height=NodeHeight(p);

            //Case 1: LL rotation.
                if(balanceFactor(p)==2 && balanceFactor(p->left)==1){//LL configuration condition.
                    return LLRotation(p);
                }else if(balanceFactor(p)==2 && balanceFactor(p->left)==-1){//LR configuration condition.
                    return LRRotation(p);
                }else if(balanceFactor(p)==-2 && balanceFactor(p->left)==-1){//RR configuration condition.
                    return RRRotation(p);
                }else if(balanceFactor(p)==-2 && balanceFactor(p->left)==1){//RL configuration condition.
                    return RLRotation(p);
                }

            return p;
        }

};

int main(){
return 0;
}