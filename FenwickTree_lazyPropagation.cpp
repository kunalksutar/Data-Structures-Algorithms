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
            for(int j=2*i;j<=n;j+=i){
                arr[i]=1;
            }
        }
    }return res;
}


struct ST{//will return the sum of the elements in the given range
private:
    void operate1(int&index){
        if(state==0){ // Tree for sumation
            seg[index]=seg[2*index+1]+seg[2*index+2];

        }else if(state==1){ // Tree for minimum return
            seg[index]=min(seg[2*index+1],seg[2*index+2]);   

        }else if(state==2){ // Tree for maximum return 
            seg[index]=max(seg[2*index+1],seg[2*index+2]);

        }else if(state==3){ // Tree for GCD 
            seg[index]=gcd(seg[2*index+1],seg[2*index+2]);

        }else if(state==4){ // Tree for XOR
            seg[index]=seg[2*index+1]^seg[2*index+2];
        }
    }

    ll operate2(ll&left,ll&right){
        if(state==0){ // Tree for sumation
            return left+right;

        }else if(state==1){ // Tree for minimum return  
            return min(left,right);

        }else if(state==2){ // Tree for maximum return 
            return max(left,right);

        }else if(state==3){ // Tree for GCD 
            return gcd(left,right);

        }else if(state==4){ // Tree for XOR
            return left^right;
        }

        return -1;
    }

public: 
    vector<ll>seg,lazy;
    int state;

    ST(int _n,int _state){

        //taking the size of the segment array as 4*n+5 for safe measures
        seg.resize(4*_n+5);
        lazy.resize(4*_n+5,0);
        state=_state;
    }

    void build(int index,int low,int high,vector<int>&arr){
        if(low==high){
            seg[index]=arr[low];
            return;//do no forget to return the funcion other wise will 
            //will not run only.
        }

        int mid=(low+high)/2;

        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);

        //seg[index]=seg[2*index+1]+seg[2*index+2];

        operate1(index);
    }

    void update(int index,int low,int high,int l,int r,int val){
       
        //first we will update the previous updates if left.
        if(lazy[index]){//meaning some updates left
            seg[index]+=(high-low+1)*lazy[index];
            //that is the same reason why it is called 
            //"lazy propagation" it updates later on.
            
            if(low!=high){//meaning if there are nodes below
            //we will down propagte;

                lazy[2*index+1]+=lazy[index];
                lazy[2*index+2]+=lazy[index];
            }

            lazy[index]=0;//since we have down propagted it once, 
            //we will turn it down to zero

            //also notice this has not completely down progated it here as well
            //it will again be executed those child nodes are triggered in future.
        }

        //case 1 : no overlap at all.
        if(low>r||l>high){
            return;
        }

        //case 2 : complete overlap.
        if(l<=low && high<=r){
            seg[index]+=(high-low+1)*val;//since that will be the number of terms inside

            //again down propagate if it has kids
            if(low!=high){
                lazy[2*index+1]+=val;
                lazy[2*index+2]+=val;
            }

            return;
        }

        //case 3 : partial overlap.
        int mid=(low+high)/2;

        update(2*index+1,low,mid,l,r,val);
        update(2*index+2,mid+1,high,l,r,val);

        //seg[index]=seg[2*index+1]+seg[2*index+2];

        operate1(index);
    }

    ll query(int index,int low,int high,int l,int r){

        //similar to that of the update method, we will first
        //have to update the nodes if there is any lazy left in it
        //copy pasting the exact code from above
        if(lazy[index]){//meaning some updates left
            seg[index]+=(high-low+1)*lazy[index];
            //that is the same reason why it is called 
            //"lazy propagation" it updates later on.
            
            if(low!=high){//meaning if there are nodes below
            //we will down propagte;

                lazy[2*index+1]+=lazy[index];
                lazy[2*index+2]+=lazy[index];
            }

            lazy[index]=0;//since we have down propagted it once, 
            //we will turn it down to zero

            //also notice this has not completely down progated it here as well
            //it will again be executed those child nodes are triggered in future.
        }

        //case 1 : no overlap
        if(low>r||l>high){
            return 0;
        }

        //case 2 : complete overlap 
        if(l<=low && high<=r){
            return seg[index];
        }

        //case 3 : partial overlap
        int mid=(low+high)/2;

        ll left=query(2*index+1,low,mid,l,r);
        ll right=query(2*index+2,mid+1,high,l,r);

        //return left+right;

        operate2(left,right);
    }
};

int main(){

int n,q,state;cin>>n>>q>>state;
vector<int>arr(n);
for(int i=0;i<n;i++)cin>>arr[i];

//or else if we do not want to make the prompt for the state 
//of the segment tree, we can pass the number while building 
//the tree itself.

ST st(n,state);
st.build(0,0,n-1,arr);

while(q--){
    
    int type;cin>>type;
    if(type==1){
        int l,r;cin>>l>>r;
        cout<<st.query(0,0,n-1,l,r)<<nline;
    }else{
        int l,r,val;cin>>l>>r>>val;
        st.update(0,0,n-1,l,r,val);
    }
}

return 0;
}