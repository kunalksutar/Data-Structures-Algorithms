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

double myPow(double x,int n){
    double ans=1;
    long nn=n;
    if(nn<0)nn*=-1;
    while(nn>0){
        if(nn%2==0){
            x=x*x;
            nn/=2;
        }else{
            ans=ans*x;
            nn-=1;
        }
    }
    if(n<0)ans=(double)1/ans;
    return ans;
}

int main(){
cout<<myPow(5,-4);
//cout<<-2/2;
return 0;
}