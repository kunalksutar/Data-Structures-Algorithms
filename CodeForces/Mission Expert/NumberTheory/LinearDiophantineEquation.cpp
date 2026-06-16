#include<bits/stdc++.h>
#define MP make_pair
#define for(a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int mod=1e9+7;
const double PI = 3.141592653589793238460;
using namespace std;

int gcd(int a,int b,int&x,int&y){
    if(b==0){
        x=1;y=0;
        return a;
    }

    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(y1*(a/b));
    return d;
}

void solve(){
    int a,b,c;
    cout<<"a : ";cin>>a;
    cout<<"b : ";cin>>b;
    cout<<"c : ";cin>>c;
    int x0,y0;

    int _gcd=gcd(a,b,x0,y0);
    if(c%_gcd){
        cout<<"No solution exists."<<endl;
        return;
    }else{
        x0*=(c/_gcd);
        y0*=(c/_gcd);
        cout<<"Solution : "<<x0<<" "<<y0<<endl;
    }cout<<endl;
}

int main(){
int t;
cout<<"T : ";
cin>>t;cout<<endl;
while(t--)solve();
return 0;
}