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

}

int main(){
int n;cin>>n;
if(n==1)cout<<1;
else if(n==2||n==3)cout<<"NO SOLUTION";
else{
    cout<<(n+1)/2<<" ";
    int i=1,j=n;
    while(true){
        cout<<j<<" ";j--;
        cout<<i<<" ";i++;
        if(i>=j)break;
    }
}
return 0;
}