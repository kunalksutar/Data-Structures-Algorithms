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

string add_ch(char ch,int x){
    string ans="";
    while(x){
        ans+=ch;
        x--;
    }

    return ans;
}

void solve(){
    string s;
    cin>>s;
    int n=s.size();

    if(n==1){
        cout<<s<<endl;
        return;
    }

    vector<int>cnt(26,0);
    string a="",b="";

    for(int i=0;i<n;i++){
        cnt[s[i]-'A']++;
    }

    int f=1;
    for(int i=0;i<26;i++){
        char ch=(i+'A');
        if(cnt[i]){
            if(f){
                a+=add_ch(ch,cnt[i]);
            }else{
                b+=add_ch(ch,cnt[i]);
            }

            f=1-f;
        }
    }

    //cout<<a<<endl;
    //cout<<b<<endl;

    string ans="";
    int i=0,j=0;

    while(i<a.size() && j<b.size()){
        if(i+1<a.size() && a[i]!=a[i+1]){
            ans+=a[i];
            ans+=b[j];
        }else{
            ans+=a[i];
            ans+=b[j];
        }

        i++;
        j++;
    }

    while(i<a.size()){
        ans+=a[i++];
    }

    while(j<b.size()){
        ans+=b[j++];
    }

    for(int i=1;i<n;i++){
        if(ans[i]==ans[i-1]){
            cout<<-1<<endl;
            return;
        }
    }

    cout<<ans<<endl;
}

int main(){
int t=1;
//cin>>t;
while(t--)solve();
return 0;
}