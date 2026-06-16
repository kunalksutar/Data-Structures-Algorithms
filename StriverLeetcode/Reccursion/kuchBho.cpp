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

    bool isPalindrome(string&s){
        int n=s.size(),left=0,right=n-1;
        if(n==1)return true;
        while(left<=right&&s[left]==s[right]){
            left++;
            right--;
        }if(left>right)return true;
        else return false;
    }

    string longestPalindrome(string s){
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                string sub=s.substr(j,n-i);
                if(isPalindrome(sub))return sub;
            }
        }return "";
    }
int main(){
string s="kwnowtwwl";
cout<<longestPalindrome(s);
return 0;
}