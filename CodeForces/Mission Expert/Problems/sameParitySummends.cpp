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
    int n,k;cin>>n>>k;

    //we can either choose even numbers or odd numbers 

    // case 1 : let's assume odd numbers 

    int n1=n-(k-1);//we will pull out k-1 numbers that are odd, being 1
    //where n1 is the last number, and that is why we pull out k-1 numbers out.

    if(n1%2 && n1>0){//making sure that the last number is also odd
        cout<<"YES"<<endl;

        for(int i=0;i<k-1;i++){
            cout<<1<<" ";
        }

        cout<<n1<<endl;
        return;
    }

    // case 2 : assuming all the evens
    // so we pull out k-1 2s out of the thing

    int n2=n-2*(k-1);

    if(n2%2==0 && n2>0){
        cout<<"YES"<<endl;

        for(int i=0;i<k-1;i++){
            cout<<2<<" ";
        }

        cout<<n2<<endl;
        return;
    }

    cout<<"NO"<<endl;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}