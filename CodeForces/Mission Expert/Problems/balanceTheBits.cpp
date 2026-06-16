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
    int n;string s;
    cin>>n>>s;

    int tot_ones=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')tot_ones++;
    }

    if(tot_ones%2 || n%2 || s[0]=='0' || s[n-1]=='0'){
        cout<<"NO"<<endl;
        return;
    }

    string a="",b="";

    int ones=0;
    int f=1;

    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(2*ones<tot_ones){
                a.push_back('(');
            }else{
                a.push_back(')');
            }

            ones++;

            b.push_back(a.back());
        }else{
            if(f){
                a.push_back('(');
                b.push_back(')');
            }else{
                a.push_back(')');
                b.push_back('(');
            }  

            f=1-f;
        }
    }
    
    cout<<"YES"<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}