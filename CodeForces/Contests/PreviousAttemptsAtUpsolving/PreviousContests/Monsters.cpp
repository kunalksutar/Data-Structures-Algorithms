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
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
using namespace std;

void solve(){
    int n,k;cin>>n>>k;
    vector<pair<int,int>>A(n+1);
    A[0].first=0;A[0].second=0;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        if(a%k==0)A[i].first=-k;
        else A[i].first=-a%k;
        A[i].second=i;
    }
    sort(all(A));
    for(int i=0;i<n;i++)cout<<A[i].second<<" ";
    cout<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}