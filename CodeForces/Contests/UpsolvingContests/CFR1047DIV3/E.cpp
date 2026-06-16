#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
#define ff first
#define ss second
#define MP make_pair
#define nline endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
#define rep(a,b,c)for(ll a=(b);a<(c);a++)
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

priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

int get_mex(vi&a){
    int x=0;
    unordered_set<int>st(a.begin(),a.end());

    while(st.count(x))x++;

    return x;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vi a(n);
    map<int,int>cnt1,cnt2;

    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt1[a[i]]++;
    }

    long long sum1=0;
    int mex=get_mex(a);

    for(int i=0;i<n;i++){//after k=1
        if(a[i]>mex || cnt1[a[i]]>1){
            a[i]=mex;
        }

        sum1+=a[i];
        cnt2[a[i]]++;
    }

    mex=get_mex(a);
    cnt1.clear();
    long long sum2=0;
    
    for(int i=0;i<n;i++){//after k=2
        if(a[i]>mex || cnt2[a[i]]>1){
            a[i]=mex;
        }

        sum2+=a[i];
        cnt1[a[i]]++;
    }

    mex=get_mex(a);
    cnt2.clear();
    long long sum3=0;

    for(int i=0;i<n;i++){//after k=3
        if(a[i]>mex || cnt1[a[i]]>1){
            a[i]=mex;
        }

        sum3+=a[i];
        cnt2[a[i]]++;
    }

    if(k==1){
        cout<<sum1<<endl;
    }else if(k%2==0){
        cout<<sum2<<endl;
    }else{
        cout<<sum3<<endl;
    }


}

int main(){
int t;
cin>>t;
while(t--)solve();
return 0;
}