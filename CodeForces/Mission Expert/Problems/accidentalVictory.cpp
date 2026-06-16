#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

bool canWin(vector<pair<int,int>>&vec,int index){
    //will check if the given candidate can win or not
    ll sum=vec[index].first;
    
    for(int i=0;i<vec.size();i++){
        if(i==index)continue;
        else if(sum<vec[i].first)return false;
        sum+=vec[i].first;
    }

    return true;
}

void solve(){
    int n;cin>>n;
    ll sum=0;
    //number of games played : n-1
    //number of players : n
    vector<pair<int,int>>vec(n);
    //      {tokens,number}

    for(int i=0;i<n;i++){
        cin>>vec[i].first;
        vec[i].second=i+1;
        sum+=vec[i].first;
    }

    sort(vec.begin(),vec.end());

    int left=0,right=n-1;
    int index=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(canWin(vec,mid)){
            index=mid;
            right=mid-1;
        }else left=mid+1;
    }

    vector<int>v;
    for(int i=index;i<n;i++){
        v.push_back(vec[i].second);
    }

    sort(v.begin(),v.end());
    cout<<v.size()<<endl;

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;
}

int main(){
int t;cin>>t;//t=1;
while(t--)solve();
return 0;
}