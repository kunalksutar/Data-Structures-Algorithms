#include<bits/stdc++.h>
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
#define ff first
#define ss second
#define MP make_pair
#define nline endl
typedef long long ll;
using namespace std;
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}

struct Node{
    int open;
    int close;
    int full;

    Node(int _open,int _close,int _full){
        open=_open;
        close=_close;
        full=_full;
    }

    Node(){
        open=0;
        close=0;
        full=0;
    }
};

Node merge(Node&a,Node&b){
    Node res=Node();
    res.full=a.full+b.full+min(a.open,b.close);
    res.open=a.open+b.open-min(a.open,b.close);
    res.close=a.close+b.close-min(a.open,b.close);

    return res;
}

void build(int index,int low,int high,vector<Node>&seg,string&s){
    if(low==high){

        if(s[low]=='('){
            seg[index].open=1;
        }else seg[index].close=1;

        return;
    }

    int mid=(low+high)/2;

    build(2*index+1,low,mid,seg,s);
    build(2*index+2,mid+1,high,seg,s);

    seg[index]=merge(seg[2*index+1],seg[2*index+2]);
}

Node query(int index,int low,int high,int l,int r,vector<Node>&seg){
    //no overlap
    if(l>high||low>r){
        return Node();
    }

    //complete overlap
    if(l<=low && high<=r){
        return seg[index];
    }

    //partial overlap
    int mid=(low+high)/2;

    Node left=query(2*index+1,low,mid,l,r,seg);
    Node right=query(2*index+2,mid+1,high,l,r,seg);

    Node res(left.open+right.open-min(left.open,right.close),
             left.close+right.close-min(left.open,right.close),
             left.full+right.full+min(left.open,right.close));
    
    return res;
}

int main(){

string s;cin>>s;

int n=s.size();
int m;cin>>m;

vector<Node>seg(4*n+5);
build(0,0,n-1,seg,s);

while(m--){
    int l,r;cin>>l>>r;
    l--;r--;

    cout<<query(0,0,n-1,l,r,seg).full*2<<nline;
}

return 0;
}