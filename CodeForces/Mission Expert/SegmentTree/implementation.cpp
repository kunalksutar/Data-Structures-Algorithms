#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define MP make_pair
#define ll long long 
using namespace std;
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}
#define ff first
#define ss second

void build(int index,int low,int high,vector<int>&arr,vector<int>&seg){
    //writing code for answer minimum in the given range queury

    if(low==high){
        seg[index]=arr[high];
        return;
    }

    int mid=(low+high)/2;

    build(2*index+1,low,mid,arr,seg);
    build(2*index+2,mid+1,high,arr,seg);

    seg[index]=min(seg[2*index+1],seg[2*index+2]);
}

int query(int index,int low,int high,int left,int right,vector<int>&seg){
    //no overlap
    //case 1 : {low high} {left right}
    //case 2 : {left right} {low high}

    if(left>high||low>right){
        return INT32_MAX;
    }

    //complete overlap
    if(left<=low && high<=right){
        return seg[index];
    }

    int mid=(low+high)/2;
    //partial overlap

    int left_val=query(2*index+1,low,mid,left,right,seg);
    int right_val=query(2*index+2,mid+1,high,left,right,seg);

    return min(left_val,right_val);
}

void update(int index,int left,int right,int val,int i,vector<int>&seg){
    if(left==right){
        seg[index]=val;
        return;
    }

    int mid=(left+right)/2;

    if(i<=mid)update(2*index+1,left,mid,val,i,seg);
    else update(2*index+2,mid+1,right,val,i,seg);

    seg[index]=min(seg[2*index+1],seg[2*index+2]);
}


int main(){

int n,q;cin>>n>>q;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}

vector<int>seg(4*n+1);
build(0,0,n-1,arr,seg);//O(n)

while(q--){
    int l,r;cin>>l>>r;
    cout<<query(0,0,n-1,l,r,seg)<<endl;
}

return 0;
}