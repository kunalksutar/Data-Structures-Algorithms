#include<iostream>
using namespace std;

int main(){
int n,k;cin>>n>>k;
int *A;
A=new int[n];
for(int i=0;i<n;i++){
    cin>>A[i];
}

int team_count;
if(A[k-1]==0){
    team_count=0;
    while(A[team_count]>0){
        team_count++;
    }
}else{
    team_count=k;
    while(A[team_count]==A[k-1] && team_count<n){
        team_count++;
    }
}
cout<<team_count;

delete []A;
return 0;
}