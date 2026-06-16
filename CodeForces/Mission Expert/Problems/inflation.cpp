#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

bool check(ll x,int k,vector<ll>&prefix_sum){
    ll exp=0;
    for(int i=1;i<prefix_sum.size();i++){
        exp+=100*(prefix_sum[i]-prefix_sum[i-1]);
        exp-=k*(prefix_sum[i-1]);
        if(exp>k*x)return false;
        exp=0;
    }return true;
}

ll binsearch(int n,int k,vector<ll>&prefix_sum){
    //will have runtime of O(nlogn)
    ll left=0,right=1e11;
    ll ans=0;
    while(left<=right){
        ll mid=(left+right)/2;
        if(check(mid,k,prefix_sum)){
            ans=mid;right=mid-1;
        }else left=mid+1;
    }return ans;
}

void solve(){
    //trying out greedy approach first.
    int n,k;cin>>n>>k;
    vector<ll>prefix_sum(n,0);
    cin>>prefix_sum[0];
    for(int i=1;i<n;i++){
        int x;cin>>x;
        prefix_sum[i]=prefix_sum[i-1]+x;
    }

    cout<<binsearch(n,k,prefix_sum)<<endl;
}

int main(){
//cout<<64424509539%INT32_MAX;
int t;cin>>t;
while(t--)solve();
return 0;
}