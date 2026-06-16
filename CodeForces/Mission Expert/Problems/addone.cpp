#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

int m_maxx=2*10e5;

void fill(vector<vector<int>>&dp){
    for(int i=0;i<10;i++){
        dp[i][0]=1;//intially each number will have one of itself only.
    }

    
    for(int digit=0;digit<10;digit++){
        for(int i=0;i<m_maxx;i++){

        }
    }
}

int main(){
int t;cin>>t;
vector<vector<int>>dp(10,vector<int>(m_maxx));
fill(dp);

while(t--){
    int n,m;cin>>n>>m;
    int ans=0;
}
return 0;
}