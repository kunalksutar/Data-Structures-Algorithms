#include<iostream>
using namespace std;

void perm(char s[],int k){
static int temp[10]={0};
static char res[10];

if(s[k]=='\0'){
    res[k]='\0';
    cout<<res<<endl;
}else{

    for(int i=0;s[i]!='\0';i++){
        if(temp[i]==0){//if that letter is not taken.
            res[k]=s[i];//we add that letter to result.
            temp[i]=1;//now that we have taken the letter, we will have to...
            //set it as occupied.
            perm(s,k+1);
            //after the above recurrsion is called, we are coming back up.
            temp[i]=0;//we set this as not taken when we call backwards.
        }
    }
}
}

int main(){
char name[]="ABCDE";
perm(name,0);
return 0;
}