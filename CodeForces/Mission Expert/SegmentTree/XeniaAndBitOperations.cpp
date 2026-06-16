#include<bits/stdc++.h>
#define MP make_pair
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}
#define nline endl
#define ff first
#define ss second

void build(int index,int low,int high,vector<int>&arr,vector<int>&seg,int op){
    if(low==high){
        seg[index]=arr[low];
        return;
    }

    int mid=(low+high)/2;

    build(2*index+1,low,mid,arr,seg,1-op);
    build(2*index+2,mid+1,high,arr,seg,1-op);

    if(op){
        seg[index]=seg[2*index+1]|seg[2*index+2];
    }else{
        seg[index]=seg[2*index+1]^seg[2*index+2];
    }
}

void update(int index,int low,int high,int i,vector<int>&seg,vector<int>&arr,int op){
    //low and high through the 'arr' and not the 'seg'
    if(low==high && low==i){
        seg[index]=arr[low];//since we have already updated the arr before calling this function
        return;
    }

    int mid=(low+high)/2;

    if(i<=mid){
        update(2*index+1,low,mid,i,seg,arr,1-op);
    }else{
        update(2*index+2,mid+1,high,i,seg,arr,1-op);
    }

    if(op){
        seg[index]=seg[2*index+1]|seg[2*index+2];
    }else{
        seg[index]=seg[2*index+1]^seg[2*index+2];
    }
}

int main(){
int n,m;cin>>n>>m;
int num=pow(2,n);
vector<int>arr(num),seg(4*num+5);
for(int i=0;i<num;i++)cin>>arr[i];

int op;//1 : or operation
      //0 : xor operation

if(n%2)op=1;
else op=0;

build(0,0,num-1,arr,seg,op);

while(m--){
    int index,val;cin>>index>>val;

    index--;
    arr[index]=val;
    update(0,0,num-1,index,seg,arr,op);
    
    cout<<seg[0]<<nline;
}

return 0;
}