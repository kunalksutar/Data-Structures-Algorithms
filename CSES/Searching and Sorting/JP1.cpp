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
if(n==1){
    cout<<1;
    return 0;
}

set<int>st;

for(int i=0;i<n;i++){
    st.insert(i+1);
}

auto =it=st.begin();
it++;

while(!st.empty()){
    cout<<*it<<" ";
    auto temp=it;
    it++;st.erase(temp);

    if(it==st.end()){
        it=st.begin();
        it++;
    }else it++;
        
    if(it==st.end()){
        it=st.begin();
    }
}

return 0;
}