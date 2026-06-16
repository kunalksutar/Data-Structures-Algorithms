#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>vec(n);
    int minn=INT32_MAX;
    int index=-1;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(minn>vec[i]){
            minn=vec[i];
            index=i;
        }
    }
    
    int op=0;
    for(int i=0;i<n;i++){
        if(vec[i]!=minn+abs(index-i))op++;
    }cout<<op<<endl;

    for(int i=0;i<n;i++){
        if(vec[i]!=minn+abs(index-i)){
            cout<<index+1<<" "<<i+1<<" "<<minn<<" "<<minn+abs(index-i)<<endl;
        }
    }
    
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}