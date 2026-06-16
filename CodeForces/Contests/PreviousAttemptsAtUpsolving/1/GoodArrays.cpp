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
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        map<int,int>count1;//will store frequencies of each number
        long long sum=0;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            count1[x]++;
            sum+=x;
        }
        if(sum>=count1[1]+n && n!=1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}