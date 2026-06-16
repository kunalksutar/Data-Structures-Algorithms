#include<vector>
#include<string>
#include<iostream>
#include<unordered_set>
using namespace std;

int recurr(int index,int k,string s,unordered_set<int>&st){
    if(index<0)return k==0?1:0;
    else if(k==0)return 1;
    int mod=1e9+7;

    int take=0,notTake;
    if(st.find(s[index])==st.end()){
        st.insert(s[index]);
        take=recurr(index-1,k-1,s,st);
        st.erase(s[index]);
    }notTake=recurr(index-1,k,s,st);

    return (take%mod)+(notTake%mod);
}

int solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;int mod=1e9+7;
    unordered_set<int>st;
    cout<<recurr(n-1,k,s,st)%mod;
    cout<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}