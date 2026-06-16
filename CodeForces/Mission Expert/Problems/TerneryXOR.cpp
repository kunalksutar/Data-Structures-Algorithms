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
    int n;string x;
    cin>>n>>x;

    string a="1",b="1";

    int f=0;
    
    //f=0 : so far both are same
    //f=1 : a is larger and hence we will minimize a 
    //f=2 : b is larger and we will minimize b

    for(int i=1;i<n;i++){
        if(x[i]=='2'){
            
            if(f=='2'){//b is larger
                a+='2';
                b+='0';
            }else if(f=='1'){//if a is bigger
                a+='0';
                b+='2';
            }else{
                //if none is bigger
                a+='1';
                b+='1';
            }

        }else if(x[i]=='1'){

            if(f=='2'){//b is larger
                a+='1';
                b+='0';
            }else{
                a+='0';
                b+='1';
            }

            if(!f){
                f='2';
            }

        }else{//if x[i]=='0'
            a+='0';
            b+='0';
        }
    }

    cout<<a<<endl;
    cout<<b<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}