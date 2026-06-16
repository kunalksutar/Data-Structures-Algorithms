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
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    vector<int>freq(n+1,0);

    deque<pair<int,ll>>dq;

    int mex=0;
    ll sum=0;

    for(int i=1;i<=n;i++){

        freq[arr[i]]++;

        while(freq[mex]){
            mex++;
        }

        sum+=mex;

        dq.push_back(MP(mex,1));//inserting mex with freq one, I know there will be 
        //mulitple copies back to back of mex, for that we will keep while loops to 
        //keep poping elements
    }

    ll ans=sum;

    for(int i=1;i<=n;i++){
        //we will be moving a cyclic manner : meaning we will pop the first num 
        //to the left and appending it to the back

        //so it is pretty obvious that the leftmost mex will be eliminated
        //so we do that by decreasing it's frequency by one

        //creating a pair that we can simply add later

        pair<int,ll>p=MP(arr[i],0);
        //since the condition is that if the elements in the back are smaller 
        //than p1 then the mex will remain unchaged but if found to be larger
        //then will have to pop out and update the answer, and p1 is arr[i] here
        //that is the first element in that rotation

        // step 1 : removing one mex off

        sum-=dq.front().ff;
        dq.front().ss--;

        if(dq.front().ss==0){//if freq drops to zero, we simply pop it, since of no use
            
            dq.pop_front();

        }

        while(!dq.empty() && dq.back().ff>=arr[i]){
            
            sum-=(ll)dq.back().ff*dq.back().ss;
            p.ss+=dq.back().ss;
            
            dq.pop_back();

        }   

        sum+=(ll)p.ff*p.ss;//since we removed all the values that are greater than arr[i];
        //now we have added the new values for the same

        dq.push_back(p); // will have to add the differnce in as well

        sum+=n; //why are we adding a 'n' extra like this ? keep in mind that the 
        //deque will originally have an n,1 element in the back and we have popped it out 
        //but we are forgetting that we want that in our answer, hence putting it back in

        dq.push_back(MP(n,1));//

        ans=max(ans,sum);

    }

    cout<<ans<<endl;

}

int main(){
int t;cin>>t;//t=1;
//cout<<16836511671%INT32_MAX;
while(t--)solve();
return 0;
}