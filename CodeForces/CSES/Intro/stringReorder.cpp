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

void solve(){
    string s;
    cin>>s;
    int n=s.size();

    vector<int>cnt(26,0);
    string ans="";

    for(int i=0;i<n;i++){
        cnt[s[i]-'A']++;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<26;i++){
            if(cnt[i] && (ans.size()==0||ans.back()!=(i+'A'))){
                cnt[i]--;
                ans+=(i+'A');
                //cout<<ans<<endl;

                bool can_finish=true;
                int suffix_len=n-ans.size();
                
                for(int j=0;j<26;j++){
                    if(i!=j){
                        if(cnt[j]>(suffix_len+1)/2){//not possible to place
                            can_finish=false;
                            break;
                        }
                    }else{
                        if(cnt[j]>suffix_len/2){//not possible to place
                            can_finish=false;
                            break;
                        }
                    }
                }

                if(!can_finish){
                    cnt[i]++;
                    ans.pop_back();
                }else{
                    break;
                }
            }
        }

        if(ans.size()!=1+k){
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