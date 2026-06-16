#include<iostream>
#include<cstdlib>
using namespace std;

int min(int x,int y){return x>y?y:x;}
struct point{int x;int y;};
int dist(point p1,point p2){return abs(p1.x-p2.x)+abs(p1.y-p2.y);}
void takein(point &a,point &b, point &c){cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;}

int main(){
int t;cin>>t;
for(int i=0;i<t;i++){
    struct point a,b,c;
    takein(a,b,c);
    cout<<((dist(a,b)+dist(a,c)-dist(b,c))/2)+1<<endl;
}
return 0;
}