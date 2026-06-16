#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    int n,k;cin>>n>>k;
    vector<pair<int,int>>A(n);
    vector<int>B(n),ans(n);
    for(int i=0;i<n;i++){
        cin>>A[i].first;//store the 
        A[i].second=i;
    }//so far we have taken in the first array.

    for(auto &b:B)cin>>b;//we have now taken in the second array as well.
    //now we sort both the arrays.
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    for(int i=0;i<n;i++){
        ans[A[i].second]=B[i];
    }

    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}

return 0;
}