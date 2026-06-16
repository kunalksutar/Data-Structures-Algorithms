#include<bits/stdc++.h>
#define MP make_pair
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}

void solve(){
    int n;cin>>n;
    vector<int>arr(n);
    ll even_sum=0,odd_sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i%2){//odd places since 0 indexing.
            odd_sum+=arr[i];
        }else even_sum+=arr[i];
    }
    
    if(odd_sum>even_sum){
        //that means we will take the odd positions
        for(int i=0;i<n;i+=2){
            arr[i]=1;
        }
    }else{
        for(int i=1;i<n;i+=2){
            arr[i]=1;
        }
    }

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}