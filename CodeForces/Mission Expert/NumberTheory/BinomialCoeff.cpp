#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

int inv(int base,int P){//will return the mulitplicative inverse of the the number 
    int ans=1;
    int power=P-2;
    //since we know that inverse will be given by the fernat theorem,
    //ie. = a^mod-2

    while(power){
        if(power%2){//odd power
            power--;
            ans=((ll)(ans)*(ll)(base))%P;
        }else{
            base=((ll)(base)*(ll)(base))%P;
            power/=2;
        }
    }return ans;
}

int C(int n,int k,int P,vector<int>&fact){
    if(k>n)return 0;

    int ans=fact[n];
    ans=((ll)(ans)*(ll)(inv(fact[k],P)))%P;;
    ans=((ll)(ans)*(ll)(inv(fact[n-k],P)))%P;
    return ans;
}

void solve(){
    int N=1e6;
    int q,P;cin>>q,P;//number of queries;
    //where P is the the new modulo, it will also be given as an input.
    vector<int>factorial(N+1);//will store the factorial w/ %P
    factorial[0]=1;//base case 
    
    //filling the entire factorials at once that will take 10^6 operations at once
    //but will give the factorial later in O(1) constant time.
    for(int i=1;i<=N;i++){
        factorial[i]=((ll)(factorial[i-1])*(ll)(i))%P;
        //notice we first convert the numbers in long long type
        //before multiplying because the number is going to be greater than 10^9
    }

    for(int i=0;i<q;i++){
        int n,k;cin>>n>>k;
        cout<<C(n,k,P,factorial)<<endl;
    }
}

int main(){
int t;//cin>>t;
t=1;
while(t--)solve();
return 0;
}