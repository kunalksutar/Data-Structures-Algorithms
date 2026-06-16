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

struct range{
    int left;
    int right;
    int index;
};

bool compare(range&a,range&b){
    //basicly this comparison will make sure that 
    //the ranges are sortin wrt to the starting 
    //and if the starting points are same 
    //then we will have to make sure that wider one
    //will be saved first;
    
    if(a.left==b.left){
        return a.right>b.right;
    }

    return a.left<b.left;
}

int main(){
int n;cin>>n;
vector<range>ranges(n);
for(int i=0;i<n;i++){
    cin>>ranges[i].left;
    cin>>ranges[i].right;
    ranges[i].index=i;
}

sort(ranges.begin(),ranges.end(),compare);


vector<bool>contains(n,false);
//does this range contains some other ranges inside itself ? 

vector<bool>contained(n,false);
//is this range contained in some other range ? 

int min_end=INT32_MAX;
for(int i=n-1;i>=0;i--){
    //think of it this way, if we want to find out 
    //if the range contains any ranges in itself
    //we will have to first come from top to bottom 
    //ie. we will have to look from the smaller to bigger
    //hence making our way to the top.
    
    if(ranges[i].right>=min_end){
        contains[ranges[i].index]=true;
    }

    min_end=min(min_end,ranges[i].right);    
}

int max_end=-1;
for(int i=0;i<n;i++){
    //similarly think of this like we want to see if it was
    //contained previous, so we will have to make our way
    //from the top to bottom or rather from the 
    //bigger to smaller one (in vague words)
   
    if(ranges[i].right<=max_end){
        contained[ranges[i].index]=true;
    }

    max_end=max(max_end,ranges[i].right);
}

for(int i=0;i<n;i++){
    cout<<contains[i]<<" ";
}

cout<<endl;

for(int i=0;i<n;i++){
    cout<<contained[i]<<" ";
}

return 0;
}