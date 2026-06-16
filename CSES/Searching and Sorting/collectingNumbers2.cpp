#include<bits/stdc++.h>
#define MP make_pair
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}
#define mp make_pair
#define ff first
#define ss second

void swap(int i,int j,vector<pair<int,int>>&arr){
    int temp=arr[i].ff;
    arr[i].ff=arr[j].ff;
    arr[j].ff=temp;
}

int solve(vector<pair<int,int>>&arr){
    int ans=0;
    int prev=INT32_MAX;
    
    for(int i=0;i<arr.size();i++){
        
        if(prev)
    }
}

int main(){
int n,m;cin>>n>>m;
vector<pair<int,int>>arr(n);

for(int i=0;i<n;i++){
    cin>>arr[i].ff;
    arr[i].ss=i+1;
}

map<int,int>mp;
//position to index

for(int i=0;i<n;i++){
    mp[arr[i].ss]=i;
}

for(int i=0;i<m;i++){
    
    int a,b;cin>>a>>b;
    swap(mp[a],mp[b],arr);
    
    cout<<solve(arr)<<endl;
    swap(mp[a],mp[b],arr);
}

return 0;
}