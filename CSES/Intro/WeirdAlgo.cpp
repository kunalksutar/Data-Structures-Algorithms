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
while(true){
    cout<<n<<" ";
    if(n==1)break;
    else if(n%2==0)n=n/2;
    else n=(3*n)+1;
}
return 0;
}