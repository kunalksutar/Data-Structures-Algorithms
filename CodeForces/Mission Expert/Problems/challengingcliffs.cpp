#include<bits/stdc++.h>
#define MP make_pair
typedef long long ll;
const int mod=1e9+7;
using namespace std;


void solve(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    
    sort(arr.begin(),arr.end());

    if(n==2){
        cout<<arr[0]<<" "<<arr[1]<<endl;
        return;
    }
    
    int min_diff=INT32_MAX;
    int at_index=-1;
    for(int i=1;i<n;i++){
        if(min_diff>abs(arr[i]-arr[i-1])){
            min_diff=abs(arr[i]-arr[i-1]);
            at_index=i;
        }
    }
    
    for(int i=at_index;i<n;i++)cout<<arr[i]<<" ";
    for(int i=0;i<at_index;i++)cout<<arr[i]<<" ";

    cout<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}