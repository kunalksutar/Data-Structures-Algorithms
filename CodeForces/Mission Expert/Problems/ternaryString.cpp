#include<bits/stdc++.h>
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
#define ff first
#define ss second
#define MP make_pair
#define nline endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
bool rev(int&a,int&b){return a>b;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}
vector<ll>seive(int n){//will return all the prime numbers till n(included)
   vector<ll>res;
   vector<int>arr(n+1,0);
   for(int i=2;i<=n;i++){
       if(arr[i]==0){
           res.push_back(i);
           for(int j=i*i;j<=n;j+=i){
               arr[i]=1;
           }
       }
   }return res;
}

void solve(){
    string s;cin>>s;

    int ans=INT32_MAX;

    map<char,int>mp;

    int left=0;

    for(int right=0;right<s.size();right++){
        mp[s[right]]++;

        while(mp.size()==3){
            mp[s[left]]--;

            if(mp[s[left]]==0){
                mp.erase(s[left]);
            }

            ans=min(ans,right-left+1);

            left++;
        }
    }

    cout<<(ans==INT32_MAX?0:ans)<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}