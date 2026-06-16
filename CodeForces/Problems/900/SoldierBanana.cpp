#include<iostream>
using namespace std;

int main(){
int k,n;cin>>k>>n;
long int w;cin>>w;
long int res=((w*(w+1)*k)/2)-n;
if(res>0)cout<<res;
else cout<<0;
return 0;
}