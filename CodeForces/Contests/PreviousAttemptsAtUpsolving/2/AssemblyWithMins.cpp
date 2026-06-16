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

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>B((n*(n-1))/2);
        map<int,int>count;
        for(auto &b:B){
            cin>>b;
            count[b]++;
        }
        
        int num=n-1;
        for(auto &x:count){
            do{
                cout<<x.first<<" ";
                x.second-=num;
                num--;
            }while(x.second>0);

            if(num==0)cout<<x.first<<endl;
        }
    }
    return 0;
}