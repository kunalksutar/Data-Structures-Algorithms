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

double calPow(double x,int n){
    if(n==0)return (double)1;
    else{
        if(n%2==0)return calPow(x*x,n/2);
        else return x*calPow(x*x,n/2);
    }
}

double myPow(double x,int n){
    if(n<0){
        long nn=n;
        return (double)1/calPow(x,-nn);
    }else return calPow(x,n);
}

int main(){
cout<<myPow(5,-6);
return 0;
}