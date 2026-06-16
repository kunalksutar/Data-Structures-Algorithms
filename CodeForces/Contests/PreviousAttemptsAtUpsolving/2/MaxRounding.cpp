#include<iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(){
int t;cin>>t;
while(t--){
    string s;cin>>s;
    int length=s.size();
    s='0'+s;
    int madeZero=0;
    //NOTE: the size of the string is EXscluding the null block at the end. 
    for(int i=0;i<=length-1;i++){//Till here I have seen, rest will try on my own.
        if(s[length-i]>='5'){
            for(int j=length-madeZero;j>=length-i;j--){
                s[j]='0';
                madeZero++;
            }

            s[length-i-1]+=1;

        }
    }
    if(s[0]=='0')s.erase(0,1);
    cout<<s<<endl;
}
return 0;
}