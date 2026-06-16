#include<bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
#define MP make_pair
using namespace std;

int findIndex(vector<int>&endpoints,int start){
    //we want to find the index to the find the 
    //highest element is strictly < than the start time
    auto it=lower_bound(endpoints.begin(),endpoints.end(),start);
    if(it==endpoints.begin())return 0;
    else it--;

    //keep in mind that we want to return the index that will 
    //point to that element.
    //and also keep in mind that we will we have a 1 based indexing going on
    //in the dp array so we add a +1.
    return it-endpoints.begin()+1;
}

int main(){
int n;cin>>n;
vector<pair<int,pair<int,int>>>vec(n);
//          {end,{start,cost}}
for(int i=0;i<n;i++){
    cin>>vec[i].second.first;//start
    cin>>vec[i].first;//end
    cin>>vec[i].second.second;//cost
}

//will sort in the increasing order of ending time
sort(vec.begin(),vec.end());
vector<int>endpoints;
for(int i=0;i<n;i++)endpoints.push_back(vec[i].first);

vector<ll>dp(n+1);
dp[0]=0;//base case

for(int i=1;i<=n;i++){
    ll notTake=dp[i-1];
    ll take=vec[i-1].second.second;//price 
    //also keep in mind that we do a i-1, since the vec is zero based indexing
    
    //                            start time
    int j=findIndex(endpoints,vec[i-1].second.first);
    take+=dp[j];
    
    dp[i]=max(take,notTake);
}cout<<dp[n];
return 0;
}//https://www.youtube.com/watch?v=MJn3ogwsUbo