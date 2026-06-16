#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;
using u64 = uint64_t;//just using unsigned numbers 
using u128 = __uint128_t;
//we are only using the u128 to handle the overflow.

u64 binpower(u64 base,u64 power,u64 MOD){
    u64 ans=1;
    while(power){
        if(power%2){//odd power
            ans=(u128)ans*base%MOD;
            power--;
        }else{
            base=(u128)base*base%MOD;
            power/=2;
        }
    }return ans;
}

bool isComposite(u64 a,int s,u64 d,u64 MOD){
    u64 temp=binpower(a,d,MOD);
    if(temp==1||temp==MOD-1)return false;//this if statement takes care of the 
    //right most brackets that I have written in my book, ie. the (a^d+1)*(a^d-1)
    //also notice that we don't write the condition for temp==MOD+1 like an idiot
    //why ? because we calculate the power in terms of the MOD only and 
    //that will make sure that our result will not exceed MOD and about the concern 
    //of MOD+1, that is covered in temp==1, think about it

    for(int i=0;i<s-1;i++){//since we have computed the first 2 numbers 
    //and now we will to take care of the rest of the s-1 numbers
        temp=(u128)temp*temp%MOD;//we use u128 just to make sure that 
        //we don't get the error of overflow but since we are taking the mod 
        //it will automatocly drop down to u64 range.
        if(temp==MOD-1)return false;//if it divides then we return false
        //saying that no it is a probable prime.
    }return false;
}

void solve(){
    u64 n,MOD;cin>>n>>MOD;

    int s=0;//power of 2
    u64 d=n-1;//the odd number
    while(d%2==0){
        d/=2;
        s++;
    }

    for(int i=0;i<5;i++){
        //again randomly generating a number between 2 and N-2
        int a=2+rand()%(n-3);
        if(isComposite(a,s,d,MOD)){
            cout<<"NO"<<endl;
            return;
        }
    }cout<<"YES"<<endl;
}

int main(){
int t;//cin>>t;
t=1;
while(t--)solve();
return 0;
}