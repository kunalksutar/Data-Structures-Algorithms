#include<bits/stdc++.h>
#define MP make_pair
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    int n;cin>>n;
    vector<ll>arr(n+1);
    for(int i=1;i<=n;i++)cin>>arr[i];

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=arr[i]-i;j<=n;j+=arr[i]){
            if(j>=1 && i<j && arr[i]*arr[j]==i+j){
                ans++;
            }
        }
    }cout<<ans<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}