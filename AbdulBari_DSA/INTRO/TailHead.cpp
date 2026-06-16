#include<iostream>
using namespace std;

void tail_recurr(int n){
    if(n>0){//base condition.
        cout<<n<<" ";
        tail_recurr(n-1);
    }
}

void head_recurr(int n){
    if(n>0){//base condition.
        head_recurr(n-1);
        cout<<n<<" ";
    }
}

int main(){
    int x = 3;
    tail_recurr(x);
    cout<<endl;
    head_recurr(x);

return 0;
}