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
    int n;cin>>n;
    string s;cin>>s;

    vector<int>LLS;//will store the indices of all the elements in the LLS

    for(int i=0;i<n;i++){//similar to that of an NGE
        while(!LLS.empty() && s[LLS.back()]<s[i])LLS.pop_back();

        LLS.push_back(i);
    }

    char maxx=s[LLS[0]];

    int num_swaps=0;//the number of swaps that we be required to make the last maxx reach the end

    for(int i=0;i<LLS.size();i++){
        if(s[LLS[i]]==maxx){
            num_swaps=i+1;
        }else break;
    }

    int m=LLS.size();

    //now rotating the substring to make it sorted
    //let's say for example this is the LLS

    // z z z y x w 
    // w z z z y x 
    // w x z z z y : this the trick part, the new LLS will be z z z y x and hence 
    // the output after the operation is that and not x w z z z y 
    // . . . 

    // w x y z z z : this the what we will get finally, which is obviously sorted
    // if you see carefully it is the reverse of the LLS, so will we do that 

    for(int i=0;i<m/2;i++){//reversing the LLS within the original string
        swap(s[LLS[i]],s[LLS[m-i-1]]);
    }

    int ans=m-num_swaps;

    for(int i=0;i<n;i++){//finally we will see if the string is sorted or not 
    //after all the sorting of the LLS
        if(s[i]<s[i-1]){
            ans=-1;
            break;
        }
    }

    cout<<ans<<endl;
}

int main(){
int t;cin>>t;//t=1;
while(t--)solve();
return 0;
}