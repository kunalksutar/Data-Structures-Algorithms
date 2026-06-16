#include<iostream>
#include<string>
using namespace std;

int main(){
string a,b;cin>>a>>b;
int i=0,result=0;//will iterate through a & b respectively.
while(a[i]!='\0' && b[i]!='\0'){
    result=tolower(a[i])-tolower(b[i]);
    if(result!=0){
        if(result>0){
            cout<<1;
            return 0;
        }else if(result<0){
            cout<<-1;
            return 0;
        }
    }
    i++;
}
cout<<0;
return 0;
}