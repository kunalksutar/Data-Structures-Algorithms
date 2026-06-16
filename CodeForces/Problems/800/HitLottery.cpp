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

int main(){
    int n;cin>>n;

    int ans=n/100;
    int left=n%100;

    ans+=left/20;
    left=left%20;

    ans+=left/10;
    left=left%10;

    ans+=left/5;
    left=left%5;

    ans+=left;
    cout<<ans<<endl;
return 0;
}