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
using namespace std;

void solve(){
    int n,m,k,H;cin>>n>>m>>k>>H;
    int ans=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        int temp=abs(H-x);
        if(temp%k==0 && temp/k<m && temp!=0)ans++;
    }
    cout<<ans<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}