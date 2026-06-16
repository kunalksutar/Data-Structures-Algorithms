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

int solve(int*A,int n1,int B){
    //if(n1==1)return A[0]==B?1:0;
    unordered_map<int,int>xorSoFar;//this will contain the count
    int XOR=0;
    int ans=0;
    xorSoFar[XOR]++;
    for(int i=0;i<n1;i++){
        XOR=XOR^A[i];
        ans+=xorSoFar[XOR^B];
        xorSoFar[XOR]++;
    }return ans;
}

int main(){
int A[]={4,2,2,6,2};
cout<<solve(A,5,6);
return 0;
}