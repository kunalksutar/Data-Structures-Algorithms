#include<iostream>
#include<vector>
#include "bits/stdc++.h"
using namespace std;

void problem(){
    int n,k;cin>>n>>k;
    vector<int> A(n);//will store the difficulty levels.
    for(int i=0;i<n;i++)cin>>A[i];
    sort(A.begin(),A.end());

    int longest_set=1;int count=1;
    for(int i=1;i<n;i++){
        if(A[i]-A[i-1]<=k){
            count++;
        }else{
            longest_set=max(longest_set,count);//will finally store the length of the longest.
            //elements that follow the following condition
            count=1;//and resetting the count to 1.
        }
    }
    longest_set=max(longest_set,count);//writing this here again because if...
    //all the elements are fine, then it won't execute this line only.
    cout<<n-longest_set<<endl;
}

int main(){
int t;cin>>t;
for(int i=0;i<t;i++)problem();
return 0;
}

