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
        string s="";
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                char x;cin>>x;
                if(x!='.'){
                    s=s+x;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}