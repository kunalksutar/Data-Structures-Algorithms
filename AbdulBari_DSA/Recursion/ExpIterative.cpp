#include<iostream>
using namespace std;

float exp(float x,int n){
float sum=1;
float num=1,den=1;
for(int i=1;i<n+1;i++){
    num=num*x;
    den=den*i;
    sum=sum+(num/den);
}
return sum;
}

int main(){

cout<<exp(1,10);
return 0;
}