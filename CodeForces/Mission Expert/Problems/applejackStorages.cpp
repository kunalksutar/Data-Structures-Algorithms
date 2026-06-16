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

    int n,q;
    cin>> n;

    map<int,int>cnt;

    int sum2=0,sum4=0;

    for(int i=1;i<=n;i++){
        
        int x;cin>>x;

        sum2-=cnt[x]/2;
        sum4-=cnt[x]/4;

        cnt[x]++;

        sum2+=cnt[x]/2;
        sum4+=cnt[x]/4;

    }

    cin>>q;

    for(int i=1;i<=q;i++){
        
        char ch; int x;
        cin >> ch >> x;

        sum2-=cnt[x]/2;
        sum4-=cnt[x]/4;

        if(ch=='+'){

            cnt[x]++;

        }else{

            cnt[x]--;

        }


        sum2+=cnt[x]/2;
        sum4+=cnt[x]/4;

        if(sum4>=1 && sum2>=4){

            cout<<"YES"<<endl;

        }else{
            
            cout<<"NO"<<endl;
        
        }

    }

}

int main(){
int t;//cin>>t;
t=1;
while(t--)solve();
return 0;
}