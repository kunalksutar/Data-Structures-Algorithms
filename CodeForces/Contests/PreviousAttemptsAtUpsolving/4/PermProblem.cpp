#include<cstdlib>
#include<iostream>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<list>
#include<deque>
#include<array>
#include<cassert>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
using namespace std;

void permuations(vector<int>&A,vector<vector<int>>result,vector<bool>&used,vector<int>&current,int n){
    if(current.size()==n){
        result.push_back(current);
        return;
    }

    for(int i=1;i<=n;i++){
        if(!used[i]){
            current.push_back(A[i]);
            used[i]=true;
            permuations(A,result,used,current,n);
            current.pop_back();
            used[i]=false;
        }
    }
}

void solve(){
    int n;cin>>n;
    vector<int>A(n+1);
    vector<int>current;
    vector<bool>used(n+1,false);
    vector<vector<int>>result;
    for(int i=1;i<=n;i++)A[i]=i;

    permuations(A,result,used,current,n);
    int ans=INT32_MIN;
    vector<int>max_vec;
    for(vector<int> current: result){
        int prev=current[0];
        unordered_set<int>st;

        for(int i=1;i<n;i++){
            st.insert(__gcd(prev,current[i]));
            prev=current[i];
        }
        st.insert(__gcd(current[0],current[n-1]));
        
        if(ans<int(st.size())){
            ans=int(st.size());
            max_vec=current;
        }
    }
    for(int element:max_vec)cout<<element<<" ";
    cout<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}