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

int count(int left,int right,char&ch,string&s){
    int res=0;
    
    while(left<=right){
        if(s[left++]==ch)res++;
    }

    return res;
}

int recurr(int left,int right,string&s,char ch){
    if(right==left){
        return s[left]!=ch;
    }

    int mid=(left+right)/2;
   
    int left_case=(right-left+1)/2-count(left,mid,ch,s)+recurr(mid+1,right,s,ch+1);
    int right_case=(right-left+1)/2-count(mid+1,right,ch,s)+recurr(left,mid,s,ch+1);

    return min(left_case,right_case);
}

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    cout<<recurr(0,n-1,s,'a')<<nline;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}