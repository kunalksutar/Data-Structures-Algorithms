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
int n,sum=0;cin>>n;
bitset<100001>temp;temp[0]=1;
for(int i=0;i<n;i++){
    int x;cin>>x;
    temp|=temp<<x;
}

vector<int>ans;
for(int i=0;i<100001;i++){
    if(temp[i]&&i)ans.push_back(i);
}cout<<ans.size()<<endl;

for(int element:ans)cout<<element<<" ";
//very important and intresting problem,
//first link explains the logic behind the code in very simple manner 
//and the second link gives the most consize and the efficient answer using bitset
//https://www.youtube.com/watch?v=PXdOyrbNr78
//https://www.youtube.com/watch?v=lJAYDAhPOpI
return 0;
}