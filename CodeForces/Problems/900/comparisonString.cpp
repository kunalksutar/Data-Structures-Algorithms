#include<iostream>
#include<string>
using namespace std;

int main(){
int t;cin>>t;
for(int i=0;i<t;i++){
    string s;int n;cin>>n>>s;
    int ans=1,curr=1;
    for(int j=1;j<n;j++){
        if(s[j]!=s[j-1])curr=1;//knock it back down to one.
        else curr++;
        ans=max(ans,curr);
    }
    cout<<ans<<endl;
}
return 0;
}