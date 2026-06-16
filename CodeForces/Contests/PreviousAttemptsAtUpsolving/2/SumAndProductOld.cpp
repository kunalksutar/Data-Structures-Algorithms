#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> &A,int n){
    int sum,pdt;cin>>sum>>pdt;
    int q=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]+A[j]==sum && A[i]*A[j]==pdt)q++;
        }
    }
    cout<<q<<" ";
}

int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)cin>>A[i];
    int q;cin>>q;
    while(q--){
        solve(A,n);
    }
    cout<<endl;
}
return 0;
}