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
        vector<pair<int,int>>A(n);
        vector<int>B(n);
        cin>>A[0].first;A[0].second=0;
        B[0]=A[0].first;
        bool isSorted=true;
        for(int i=1;i<n;i++){
            cin>>A[i].first;
            B[i]=A[i].first;
            A[i].second=i;
            if(A[i].first<A[i-1].first)isSorted=false;
        }
        if(isSorted){cout<<0<<endl;continue;}

        sort(all(A));//the leftmost number is min and rightmost is max.
        int op=0;

    }
    return 0;
}