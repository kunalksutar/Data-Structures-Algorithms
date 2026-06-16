#include<iostream>
using namespace std;

struct Term{
    int coeff;
    int exp;
};

struct Poly{
    int n;//number of terms.
    struct Term *t;//dynamically create an array for storing terms.
};

struct Poly merge(struct Poly* p1,struct Poly* p2){
    struct Poly p3;
    p3.t=new struct Term[p1->n+p2->n];
    int i=0;//will iterate through p1->t[]
    int j=0;//through p2->t[]
    int k=0;//through p3->t[]
    while(i<p1->n && j<p2->n){
        if(p1->t[i].exp>p2->t[j].exp){
            p3.t[k++]=p2->t[j++];
        }else if(p1->t[i].exp<p2->t[j].exp){
            p3.t[k++]=p1->t[i++];
        }else{
            p3.t[k].coeff=p1->t[i].coeff+p2->t[j].coeff;
            p3.t[k++].exp=p1->t[i++].exp+p2->t[j++].exp;
        }
    }

}


int main(){

    struct Poly p;
    cout<<"enter the number of terms : ";
    cin>>p.n;

    p.t=new struct Term [p.n];

    cout<<"enter polynomial terms : ";
    for(int i=0;i<p.n;i++){
        cin>>p.t[i].coeff>>p.t[i].exp;
    }


    return 0;
}