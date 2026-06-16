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
    long long n;cin>>n;
    long long ans=0;
    while(n!=0){
        ans+=n;n/=2;
    }
    cout<<ans<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}