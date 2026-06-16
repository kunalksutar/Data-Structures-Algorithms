#include<bits/stdc++.h>
//#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>vec(n);
    vector<pair<int,int>>ans;

    for(int i=0;i<n;i++)cin>>vec[i];

    int index=-1;
    for(int i=1;i<n;i++){
        if(vec[i]!=vec[0]){
            index=i;
            ans.push_back(make_pair(1,index+1));
            //{index of the first element,index of the different gang}
        }
    }

    if(index==-1){
        cout<<"NO"<<endl;
        return;
    }

    for(int i=1;i<n;i++){
        if(vec[i]==vec[0]){
            //if it is from the same gang as one, will take the connection 
            //from the gang that is different from the first gang.
            //so basicly the 'index' will work as a middle man
            ans.push_back(make_pair(index+1,i+1));
        }
    }

    cout<<"YES"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}   

int main(){
int t;cin>>t;//t=1;
while(t--)solve();
return 0;
}