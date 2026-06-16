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
    int n;cin>>n;
    int ans=1;
    int prev;cin>>prev;
    for(int i=1;i<n;i++){
        int curr;cin>>curr;
        //cout<<(curr&prev)<<endl;
        if((curr&prev)!=0){
            ans++;
            prev=curr;
        }else prev=(curr&prev);
    }
    cout<<ans<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}