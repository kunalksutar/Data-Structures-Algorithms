#include<iostream>
using namespace std;

int main(){
int n;cin>>n;
int *A[3];
A[0]=new int[n];
A[1]=new int[n];
A[2]=new int[n];

for(int i=0;i<n;i++){
    cin>>A[0][i]>>A[1][i]>>A[2][i];
}

int result=0;
for(int i=0;i<n;i++){
    if(A[0][i]+A[1][i]+A[2][i]>=2){
        result++;
    }
}
cout<<result;
return 0;
}