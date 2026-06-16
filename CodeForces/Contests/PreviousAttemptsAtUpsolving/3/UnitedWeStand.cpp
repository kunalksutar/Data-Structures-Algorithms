#include <cstdlib>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <list>
#include <deque>
#include <array>
#include <cassert>
#include <algorithm>
#include <string>
#define all(x) x.begin(),x.end()
using namespace std;

void solve(){
    int n;cin>>n;
        map<int,int>count;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            count[x]++;
        }
        
        bool flag=true;
        for(auto &a:count){
            if(flag){
                if(a.second==n){
                    cout<<-1<<endl;
                    return;
                }
                cout<<a.second<<" "<<n-a.second<<endl;
                for(int i=0;i<a.second;i++)cout<<a.first<<" ";
                cout<<endl;
                flag=false;
                continue;
            }
            for(int i=0;i<a.second;i++)cout<<a.first<<" ";
        }
        cout<<endl;
    }


int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}