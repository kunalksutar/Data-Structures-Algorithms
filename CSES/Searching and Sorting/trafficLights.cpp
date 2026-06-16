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
int x,n;cin>>x>>n;
set<int>pos;
pos.insert(0);
pos.insert(x);

multiset<int>length;
length.insert(x);

for(int i=0;i<n;i++){
    int x;cin>>x;

    pos.insert(x);
    auto it=pos.find(x);

    it--;
    int left=*it;

    it++;it++;
    int right=*it;

    it=length.find(right-left);
    length.erase(it);

    length.insert(x-left);
    length.insert(right-x);

    cout<<*length.rbegin()<<" ";
} 
return 0;
}