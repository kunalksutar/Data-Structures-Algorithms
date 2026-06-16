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

   int bestClosingTime(string customers){
        int penalty=0,n=customers.size();
        for(int i=0;i<n;i++)if(customers[i]=='N')penalty++;

        int j=n,minPen=penalty;
        for(int i=n-1;i>=0;i--){
            //cout<<penalty<<endl;
            if(customers[i]=='Y')penalty++;
            else penalty--;
            if(minPen>=penalty){
                j=i;minPen=penalty;
            }
        }return j;
    }

int main(){
    string s="YYNY";
    cout<<bestClosingTime(s);
return 0;
}