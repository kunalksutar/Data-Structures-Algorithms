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

vector<int>contains(n,0);
vector<int>contained(n,0);

multiset<int>st;//will store the end points 

for(int i=n-1;i>=0;i--){

    auto it=st.upper_bound(ranges[i].right);

    if(it!=st.begin()){
        it--;
        contains[ranges[i].index]=distance(st.begin(),it)+1;
    }
    
    st.insert(ranges[i].right);
}

st.clear();

for(int i=0;i<n;i++){
    
    auto it=st.lower_bound(ranges[i].right);

    contained[ranges[i].index]=st.size()-distance(st.begin(),it);

    st.insert(ranges[i].right);
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