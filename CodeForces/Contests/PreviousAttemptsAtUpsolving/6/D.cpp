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

    ll n,k;cin>>n>>k;
    ll minn=INT64_MAX;

    vector<ll>arr(n);

    for(int i=0;i<n;i++){

        cin>>arr[i];
        arr[i]-=k;

    }

    sort(all(arr));

    if(arr[0]<0 && arr[n-1]>0){
        //if there is pos and neg, both the terms then we can not make 
        //all the elements same soch ke dekh. because if we try to slide 
        //one number from neg to pos it will push the other number even 
        //back to neg

        cout<<-1<<endl;
        return;

    }

    int zeros=0;
    int non_zeros=0;

    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zeros=1;
        }else{
            non_zeros=1;
        }
    }

    if(zeros && non_zeros){
        //if one of the numbers is zero then there is no way we can make
        //all numbers equal , soch ke dekh because if we want to make all
        //zero, even if we give endless birth to zero we can not make all zeros
        //and if non zero then it will push one to pos and one to neg.

        cout<<-1<<endl;
        return;

    }

    if(zeros){
        //if it only contains zeros then we will simply need 0 operations 
        //why ? because all the numbers are 0 meaning same 
        //we actually have to call for this here seperately because 
        //it will not allow to divide 0 by 0 further in the code

        cout<<0<<endl;
        return;

    }

    for(int i=0;i<n;i++){
        if(arr[i]<0){
            arr[i]=-arr[i];
        }
    }


    ll GCD=arr[0];

    for(int i=0;i<n;i++){

        GCD=gcd(arr[i],GCD);

    }

    ll ans=0;

    for(int i=0;i<n;i++){

        ans+=arr[i]/GCD;

    }

    cout<<ans-n<<endl;
    
}

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}