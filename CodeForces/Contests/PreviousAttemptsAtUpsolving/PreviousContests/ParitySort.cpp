#include <cstdlib>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <list>
#include <deque>
#include <array>
#include <cassert>
#include <algorithm>
#include <string>
#define all(x) x.begin(),x.end()
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>A(n+1),B(n+1);
    A[0]=B[0]=0;
    for(int i=1;i<=n;i++){cin>>A[i];B[i]=A[i];}
    sort(all(B));
    for(int i=1;i<=n;i++){if(A[i]%2!=B[i]%2){cout<<"NO"<<endl;return;}} 
    cout<<"YES"<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}