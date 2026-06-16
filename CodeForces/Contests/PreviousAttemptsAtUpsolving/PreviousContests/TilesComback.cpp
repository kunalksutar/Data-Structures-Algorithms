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

bool solve(){
    int n,k;cin>>n>>k;
        vector<int>A(n);
        for(int i=0;i<n;i++)cin>>A[i];

        int i=0,j=n-1;//i from the left & j from the right.
        int left=0,right=0;//how many times we have used the k-value.
        int k_left=k,k_right=k;
        if(A[0]==A[n-1]){k_left=k/2;k_right=k-k_left;}

        for(;i<n && left<k_left;i++){
            if(A[0]==A[i])left++;
        }
        
        for(;j>=0 && right<k_right;j--){
            if(A[j]==A[n-1])right++;
        }
        
        return j+2>i;
}

int main(){
    int t;cin>>t;
    while(t--){
        cout<<(solve()?"YES":"NO")<<endl;
    }
    return 0;
}