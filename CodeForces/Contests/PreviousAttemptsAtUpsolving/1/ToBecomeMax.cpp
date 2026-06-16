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

bool canMakeValue(vector<int>&A, int attemptValue, int attemptsLeft,int index){
    if(A[index]>=attemptValue)return true;//meaning if we can increase it to the desired 
    //value.
    if(index==A.size()-1)return false;//let's say after calling multiple times,we ended up...
    //reaching the last index, meaning we are demanding that that value must be increaed,
    //which is clearly not possible, hence we return false.

    int opsRequiredToMaxCurr=attemptValue-A[index];
    if(opsRequiredToMaxCurr>attemptsLeft)
        return false;
    else 
        return canMakeValue(A,attemptValue-1,attemptsLeft-opsRequiredToMaxCurr,index+1);
}

int getMaxForIndex(vector<int>&A,int index,int opsAllowed){    
    if(index==A.size()-1)return A[index];//since if it is the last element we can NOT change
    //The number.

    int lowerBound=A[index];
    int upperBound=A[index]+opsAllowed;//opsAllowed is 'k'
    
    while(lowerBound<upperBound){
        int attemptValue=(lowerBound+upperBound)/2+1;
        if(canMakeValue(A,attemptValue,opsAllowed,index)){
            lowerBound=attemptValue;
        }else upperBound=attemptValue-1;
    }
    return lowerBound;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int>A(n);
        for(int i=0;i<n;i++)cin>>A[i];
        int maxPossible=0;
        for(int i=0;i<n;i++){
            maxPossible=max(maxPossible,getMaxForIndex(A,i,k));
        }
        cout<<maxPossible<<endl;
    }
    return 0;
}