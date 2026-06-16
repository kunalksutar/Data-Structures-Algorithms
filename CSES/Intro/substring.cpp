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

void solve(){
    string s;cin>>s;
    stack<char>st;
    bool karnapadega=false;
    for(char x:s){
        if(x=='(')st.push('(');
        else if(!st.empty() && st.top()=='(' && x==')')st.pop();
        else if(st.empty() && x==')'){
            karnapadega=true;
            break;
        }
    }

    if(!karnapadega && st.empty()){
        cout<<"NO"<<endl;
        return;
    }else cout<<"YES"<<endl;

    int n=s.size();
    for(int i=1;i<n;i++){
        if(s[i-1]==')' && s[i]=='('){
            cout<<"(())";
            if(i==n-2)cout<<"()";
        }else{
            
        }
    }cout<<endl;
}

int main(){
int t;cin>>t;
while(t--){
    solve();
}
return 0;
}