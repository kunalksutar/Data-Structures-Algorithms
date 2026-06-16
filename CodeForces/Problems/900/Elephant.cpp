#include<iostream>
using namespace std;

int main(){
int x;cin>>x;
if(x<6)cout<<1;
else if(x%5!=0)cout<<(x/5)+1;
else cout<<x/5;
return 0;
}