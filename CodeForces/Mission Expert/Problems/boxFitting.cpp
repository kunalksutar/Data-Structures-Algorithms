#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

void solve(){
    int n,box_width;cin>>n>>box_width;
    
    multiset<int>st;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        st.insert(x);
    }

    int ans=1,capacity=box_width;
    while(!st.empty()){
        auto it=st.upper_bound(capacity);
        if(it==st.begin()){
            ans++;
            capacity=box_width;
        }else{
            it--;
            capacity-=*it;
            st.erase(it);
        }
    }

    cout<<ans<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}