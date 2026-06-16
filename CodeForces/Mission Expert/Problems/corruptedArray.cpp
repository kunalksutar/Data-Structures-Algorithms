#include<bits/stdc++.h>
#define MP make_pair
//#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int MOD=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

int binsearch(ll&target,int&n,vector<int>&vec){
    //will return the index of the left most 
    //target element if present otherwise -1
    int left=0,right=n+1;
    int ans=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(vec[mid]>=target){
            right=mid-1;
            if(vec[mid]==target)ans=mid;
        }else left=mid+1;
    }return ans;
}

void solve(){
    int n;cin>>n;
    ll sum=0;
    vector<int>vec(n+2);
    for(int i=0;i<n+2;i++){
        cin>>vec[i];
        sum+=vec[i];
    }

    sort(vec.begin(),vec.end());
    for(int i=n+1;i>=0;i--){
        //last index = n+1;
        //& number of elements = n+2;
        ll assumed_sum=vec[i];
        ll target=sum-2*assumed_sum;
        
        int index=binsearch(target,n,vec);
        //index to the corrupted element
        if(index!=-1 && index!=i){
            for(int j=0;j<n+2;j++){
                if(j!=index && j!=i)cout<<vec[j]<<" "; 
            }cout<<endl;
            return;
        }
    }cout<<-1<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
return 0;
}