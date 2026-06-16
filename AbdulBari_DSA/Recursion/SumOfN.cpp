#include<iostream>
using namespace std;

int sum(int n){
    if(n>0){
        return sum(n-1)+n;
    }
return 0;
}

int main(){
    cout<<sum(4);
}