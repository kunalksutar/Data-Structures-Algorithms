#include<cstdlib>
#include<iostream>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<list>
#include<deque>
#include<array>
#include<cassert>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
using namespace std;

int binSearch(vector<int>&vec,int target){
    int n=vec.size();
    int left=0,right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(vec[mid]==target)return mid+2;
        else if(vec[mid]<target)left=mid+1;
        else if(vec[mid]>target)right=mid-1;
        else if(left==right && vec[mid]!=target)return left+2;
    }return left+1;
}

void solve(int n){
    vector<int>A(n);
    for(int i=0;i<n;i++)cin>>A[i];
    sort(all(A));
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int x;cin>>x;
        if(x>=A[n-1])cout<<n<<endl;
        else if(x<A[0])cout<<0<<endl;
        else cout<<binSearch(A,x)<<endl;
    }
}

int main(){
int n;cin>>n;
solve(n);
return 0;
}