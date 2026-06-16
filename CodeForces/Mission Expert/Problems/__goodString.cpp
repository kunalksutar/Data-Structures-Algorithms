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

void swap(char&x,char&y){
    char temp=x;
    x=y;
    y=temp;
}

int help(char x,char y,string&s){
    int ans=0;

    for(char ch:s){
        if(ch==x){
            ans++;
            swap(x,y);
        }
    }

    if(x!=y && ans%2){
        ans--;
    }

    return ans;
}

void solve(){
    string s;
    cin>>s;
    
    int ans=0; 

    for(char x='0';x<='9';x++){
        for(char y='0';y<='9';y++){
            ans=max(ans,help(x,y,s));
        }
    }

    cout<<s.size()-ans<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}