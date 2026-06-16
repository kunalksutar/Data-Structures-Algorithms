#include<iostream>
#include<vector>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
        int n;cin>>n;
        vector<int>A(n);
        for(auto &a:A)cin>>a;

        int ans=0;
        for(int i=0;i<n-1;i++){
            if(A[i]>A[i+1])ans=max(ans,A[i]);
        }   
        cout<<ans<<endl;     
    }
}