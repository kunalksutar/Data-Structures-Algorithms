#include<iostream>
#include <cstdlib>
using namespace std;

int main(){
int t;cin>>t;
for(int i=0;i<t;i++){
    int n,m,k,a,b;cin>>n>>m>>k>>a>>b;
    //a,b are cordinates of Vika.
    bool foundVika=false;
    for(int i=0;i<k;i++){
        int x,y;cin>>x>>y;//cordinates of her friend.
        if((x+y)%2==(a+b)%2)foundVika=true;
    }
    if(foundVika)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
return 0;
}