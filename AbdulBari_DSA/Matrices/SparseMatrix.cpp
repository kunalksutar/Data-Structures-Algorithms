#include<iostream>
using namespace std;

struct Element{
int i;//will record the row number.
int j;//column number.
int val;//value to be stored there.

};

struct Sparse{
int m;//number of row.
int n;//column.
int num;//number of non-zero elements.
struct Element *e;//we will dynamicly create array later, hence defining a pointer here.

};

void create(struct Sparse* s){

    cout<<"Enter number of dimensions :";
    cin>> s->m >> s->n;

    cout<<"Enter number of elements :";
    cin>> s->num;

    s->e = new Element[s->num];//dynamiclly creating a array in heap.

    for(int k = 0 ; k< s->num ; k++){
        cin>> s->e[k].i >> s->e[k].j >> s->e[k].val; 
    }   
}

void display(struct Sparse s){
    int k=0;
    for(int i=0; i<s.m ;i++){
        for(int j=0; j<s.n ;j++){
            if(i==s.e[k].i && j==s.e[k].j){
                cout<<s.e[k++].val<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

struct Sparse add(struct Sparse* s1,struct Sparse* s2){

    struct Sparse sum;
    sum.m=s1->m;
    sum.n=s1->n;

    sum.e = new Element[s1->num+s2->num];
    int k=0;//will iterate through sum.e[];
    int a=0;//through s1.e[]
    int b=0;//through s2.e[]

    if(s1->e[a].i > s2->e[b].i){
        sum.e[k++]=s2->e[b++];
    }else if(s1->e[a].i < s2->e[b].i){
        sum.e[k++]=s1->e[a++];
    }else{//meaning when the rows are same.
        //we will check who comes first or who comes last.
        if(s1->e[a].j > s2->e[b].j){
            sum.e[k++]=s2->e[b++];
        }else if(s1->e[a].j < s2->e[b].j){
            sum.e[k++]=s1->e[a++];
        }else{//if they are on same co-ordinates, we simply add.
            sum.e[k++].val=s1->e[a++].val+s2->e[b++].val;
        }
    }
}

int main(){

Sparse s;//we create a sparse matrix.
create(&s);
display(s);

return 0;
}