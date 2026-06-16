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

void insert(int index,vector<int>&arr,ll&ans){
    if(index==0||index==arr.size()-1)return;

    if(arr[index]>arr[index+1] && arr[index]>arr[index-1]){
        ans+=arr[index];//if we have a new local maxima
    }

    if(arr[index]<arr[index+1] && arr[index]<arr[index-1]){
        ans-=arr[index];//if we have a new local minima
    }
}

void remove(int index,vector<int>&arr,ll&ans){
    if(index==0||index==arr.size()-1)return;

    if(arr[index]>arr[index+1] && arr[index]>arr[index-1]){
        ans-=arr[index];//if we have a new local maxima
    }

    if(arr[index]<arr[index+1] && arr[index]<arr[index-1]){
        ans+=arr[index];//if we have a new local minima
    }
}

void swap(int&x,int&y){
    int temp=x;
    x=y;
    y=temp;
}

void solve(){
    int n,q;cin>>n>>q;

    vector<int>arr(n+2);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    arr[0]=arr[n+1]=INT32_MIN;//edge cases

    ll ans=0;

    for(int i=1;i<=n;i++){

        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            ans+=arr[i];//local maxima
        }

        if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
            ans-=arr[i];//local minima
        }

        //keep in mind that if there is a local minima
        //then there is bound to be a local maxima after that
        //even if it is the last element, think about it.
    }

    cout<<ans<<endl;

    while(q--){

        int l,r;cin>>l>>r;
        //l--;r--;

        //  l-1,l,l+1 ... r-1,r,r+1

        set<int>needchange;

        for(int i=-1;i<2;i++){
            if(l+i>=1 && l+i<=n){
                needchange.insert(l+i);
            }

            if(r+i>=1 && r+i<=n){
                needchange.insert(r+i);
            }
        }

        //step 1 : removal of all elements.

        for(int index:needchange){
            remove(index,arr,ans);
        }

        //step 2 : swap

        swap(arr[l],arr[r]);

        //step 3 : inserting the elements back again

        for(int index:needchange){
            insert(index,arr,ans);
        }

        cout<<ans<<endl;
    }
}   

int main(){
int t;cin>>t;
//t=1;
while(t--)solve();
return 0;
}