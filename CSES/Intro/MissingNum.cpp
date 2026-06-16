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

void solve(){

}

int main(){
long long n;cin>>n;
long long sum=0;
for(int i=1;i<n;i++){
    int x;cin>>x;
    sum+=x;
}
cout<<((n*(n+1)/2)-sum);
return 0;
}