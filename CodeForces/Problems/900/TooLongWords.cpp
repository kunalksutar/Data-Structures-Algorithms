#include<iostream>
#include<string>
using namespace std;



int main(){
int num;
cin>>num;
string *A;
A=new string[num];
for(int i=0;i<num;i++){
    cin>>A[i];
}


for(int i=0;i<num;i++){
        int length=A[i].length();
        if(length>10){
            cout<<A[i][0]<<length-2<<A[i][length-1];
        }else{
            cout<<A[i];
        }
        cout<<endl;
    }
return 0;
}