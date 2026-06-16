#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
#define ff first
#define ss second
#define MP make_pair
#define nline endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
#define rep(a,b,c)for(ll a=(b);a<(c);a++)
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

int n,m,k,a,b,c,d;

void solve(){

}

 int maximumLength(string s) {
        vector<map<int,int>>cnt(26);
        int n=s.size();
        
        int ans=-1;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                if(s[i]==s[j]){
                    
                    if(j-i>=2){
                        
                        ans=max(ans,j-i-1);
                        
                    }
                    
                }else{
                    //i=j-1;
                    
                    cnt[s[i]-'a'][j-i]++;
                    
                    break;
                }
                
            }
    
        }
        
        for(int i=0;i<26;i++){
            
            auto it=cnt[s[i]-'a'].begin();
            
            for(;it!=cnt[s[i]-'a'].end();it++){
                
                if(it->second>=3){
                    
                    ans=max(ans,it->first);
                    
                }
                
            }
            
        }
        
        return ans;
    }

int main(){
string s="aaaa";
cout<<maximumLength(s)<<endl;
return 0;
}