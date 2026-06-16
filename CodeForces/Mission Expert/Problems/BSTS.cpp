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
    int n;cin>>n;
    string s;cin>>s;

    vector<int>pos0,pos1,ans;

    for(int i=0;i<n;i++){
        int new_pos=pos0.size()+pos1.size();

        if(s[i]=='1'){
            if(pos0.size()){
                new_pos=pos0.back();
                pos0.pop_back();
                pos1.push_back(new_pos);
            }else{
                pos1.push_back(new_pos);
            }
        }else{
            if(pos1.size()){
                new_pos=pos1.back();
                pos1.pop_back();
                pos0.push_back(new_pos);
            }else{
                pos0.push_back(new_pos);
            }
        }

        ans.push_back(new_pos);
    }

    cout<<pos0.size()+pos1.size()<<nline;
    
    for(int&a:ans){
        cout<<a+1<<" ";
    }

    cout<<nline;
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}