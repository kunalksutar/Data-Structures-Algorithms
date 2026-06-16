#include<iostream>
#include<string>
using namespace std;

int main(){
int n,x=0;cin>>n;
string *A;
A=new string[n];
for(int i=0;i<n;i++){
    cin>>A[i];
    if(A[i][0]=='+' && A[i][1]=='+' && A[i][2]=='X' || A[i][0]=='X' && A[i][1]=='+' && A[i][2]=='+'){
        x++;
    }else if(A[i][0]=='-' && A[i][1]=='-' && A[i][2]=='X' || A[i][0]=='X' && A[i][1]=='-' && A[i][2]=='-'){
        x--;
    }
}
cout<<x;
return 0;
}