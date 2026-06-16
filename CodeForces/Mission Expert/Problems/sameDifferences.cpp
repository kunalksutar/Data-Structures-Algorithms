#include<bits/stdc++.h>
#define MP make_pair
#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>arr(n);
    for(0,n)cin>>arr[i];

    ll ans=0;
    map<int,int>mp;
    for(0,n){
        if(mp.find(arr[i]-i)!=mp.end())ans+=mp[arr[i]-i];
        mp[arr[i]-i]++;
    }cout<<ans<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}