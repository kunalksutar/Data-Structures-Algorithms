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

int main(){
int n;cin>>n;
multiset<int>st;

for(int i=0;i<n;i++){
    int x;cin>>x;

    auto it=st.upper_bound(x);
    
    if(it!=st.end())st.erase(it);

    st.insert(x);
}

cout<<st.size();
return 0;
}