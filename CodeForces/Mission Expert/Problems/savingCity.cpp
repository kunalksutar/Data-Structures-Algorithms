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
bool rev(ll&a,ll&b){return a>b;}
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
    int a,b;cin>>a>>b;
    string s;cin>>s;

    int n=s.size();
    map<int,int>mp;

    int start=-1;
    int end=-1;

    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            start=i;
            break;
        }
    }

    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            end=i;
            break;
        }
    }

    if(start==-1 && end==-1){
        cout<<0<<endl;
        return;
    }

    int ans=a;

    for(int i=start;i<=end;i++){
        int zeros=0;
        
        while(s[i]=='0'){
            zeros++;
            i++;
        }

        ans+=min(a,b*zeros);
    }

    cout<<ans<<endl;
}  

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}