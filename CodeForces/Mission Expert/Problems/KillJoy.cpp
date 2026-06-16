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
    int n,x;cin>>n>>x;

    ll sum=0;
    int cnt=0;//number of numbers that are equal to x

    for(int i=0;i<n;i++){
        int num;cin>>num;
        
        if(num==x){
            cnt++;
        }

        sum+=num;
    }

    if(cnt==n){
        cout<<0<<endl;
    }else if(sum==n*x || cnt>0){
        //look here that cnt > 0 will also lead to answer as one operation, how ? 
        //assume that the ith element is equal to x, then we will simply make 
        //all the changes to that ith element and the rest of the numbers will become x
        //and you must be thinking that what about the ith element then, well... 
        //we do not care, because it was already infected, read the problem statement again
        //for a clear understanding/
        cout<<1<<endl;
    }else{
        cout<<2<<endl;
    }
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}