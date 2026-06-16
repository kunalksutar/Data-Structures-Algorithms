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

int fib(int n){//iterative methods are more efficient for highly recurrsive functions like fib.
    if(n<3)return n-1;
    int f1=0,f2=1;
    for(int i=0;i<n-2;i++){
        int temp=f1;
        f1=f2;f2=temp+f1;
    }
    return f2;
}

int main(){
int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int a=fib(k-1),b=fib(k-2);
        int ans=0;
        for(int x=0;x<=(n/(2*b));x++){
            if((n-(b*x))%a==0){//meaning if there exists such F1.
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}