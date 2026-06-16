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
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
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

bool notVal(auto&it,set<int>&st){
    int i=it->ss.ff;
    int j=it->ss.ss;

    if(i==j && st.find(i)!=st.end()){
        return true;
    }
}

void solve(){
    int n;cin>>n;

    vector<int>arr(n);
    int maxx=INT32_MIN;
    int index=-1;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(maxx<arr[i]){
            maxx=arr[i];
            index=i;
        }
    }

    vector<int>b(n);

    b[0]=arr[index];
    arr[index]=0;

    cout<<b[0]<<" ";

    for(int i=1;i<n;i++){
        int curr_gcd=INT32_MIN;

        for(int j=0;j<n;j++){
            if(arr[j] && curr_gcd<__gcd(arr[j],b[i-1])){
                curr_gcd=__gcd(arr[j],b[i-1]);

                index=j;
            }
        } 
        
        b[i]=curr_gcd;
        
        cout<<arr[index]<<" ";

        arr[index]=0;
    }

    cout<<endl;
}

int main(){
int t;cin>>t;//t=1;
while(t--)solve();
return 0;
}


