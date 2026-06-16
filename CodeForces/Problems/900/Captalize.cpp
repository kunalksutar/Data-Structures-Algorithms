#include<iostream>
#include<string>
using namespace std;

int main(){
string s;cin>>s;
char firstletter=toupper(s[0]);
cout<<firstletter;
for(int i=1;s[i]!='\0';i++){
    cout<<s[i];
}
return 0;
}