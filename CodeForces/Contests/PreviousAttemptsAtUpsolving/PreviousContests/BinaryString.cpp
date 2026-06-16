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
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
using namespace std;

void solve(){//BRUTEFORCE : The code is correct, it will give correct answer but...
            //the code is slower.
    int n,k;cin>>n>>k;
    unordered_set<string>count;
    string s;cin>>s;
    for(int i=0;i<k;i++){
        string temp=s;
        int l,r;cin>>l>>r;
        sort(temp.begin()+l-1,temp.begin()+r);
        //cout<<temp<<endl;
        count.insert(temp);
    }    
    cout<<count.size()<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}