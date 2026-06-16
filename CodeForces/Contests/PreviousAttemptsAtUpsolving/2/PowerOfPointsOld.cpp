#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
void solve(vector<long long int>&A,int s,int n){
       long long int sum=0;
        for(int j=0;j<n;j++){//through the segments
            if(s==A[j]){
                sum++;
            }else{
                sum+=abs(s-A[j])+1;            
            }
        }
    
    cout<<sum<<" ";    
}

int main(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    vector<long long int> A(n);
    for(int i=0;i<n;i++)cin>>A[i];
    for(int i=0;i<n;i++)solve(A,A[i],n);
    cout<<endl;
}
return 0;
}