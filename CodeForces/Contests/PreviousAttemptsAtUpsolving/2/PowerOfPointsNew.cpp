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
        vector<pair<int,int>>A(n+1);
        vector<long long int>result(n+1);
        A[0].first=0;A[0].second=0;
        result[0]=0;
        long long int sum_from_left=0,sum_from_right=0;
        for(int i=1;i<=n;i++){
            cin>>A[i].first;
            A[i].second=i;
            sum_from_right+=A[i].first;
        }//at the end sum_from_left will be zero and sum_from_right will contain all the elements

        sort(A.begin(),A.end());

        for(int i=1;i<=n;i++){//since we are traversing from left to right.
        //the sum_from left will increase and the sum from right decrease.

        //A[i].first is s here.
            sum_from_right-=A[i].first;
            sum_from_left+=A[i].first;
            result[A[i].second]=n+1ll*A[i].first*(2*i-n)-sum_from_left+sum_from_right;
        }
        for(int i=1;i<=n;i++)cout<<result[i]<<" ";
        cout<<endl;


    }
    return 0;
}