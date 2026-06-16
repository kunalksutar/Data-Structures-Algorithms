#include<iostream>
using namespace std;

void dups(char A[]){
    int length=0;
    for(int length = 0; A[length]!='\0' ;length++){}//find length of the string.

    int hash[26]={0};//making a hash of 27 zeros.
    for(int i=0;A[i]!='\0';i++){
        hash[A[i]-97]++;//updating the hash.
    }

    for(int i=0;i<26;i++){
        if(hash[i]>1){
            cout<<char(i+97)<<" repeated "<<hash[i]<<" times."<<endl;
        }
    }
}

void dups_bitwise(char A[]){
    int length;
    for(int length = 0 ; A[length]!='\0'; length++){}//finding the length of the string.

    //in .cpp the length of int is 4 bytes or 32 bits.
    //but for hashing we only need a space of 26 bits. 
    //so 'int' will do the job.

    int hash=0;//we set this as zero so that intitally all the bits will be zero.

    for(int i=0;A[i]!='\0';i++){
        int x = 1;
        x = x << (A[i]-97); 
        if((x&hash)>0){//meaning that number is already present.
            cout<<A[i]<<" is repeated."<<endl;
        }else{
            hash=hash|x;//we turn that bit on.
        }
    }   
}

int main(){
char A[]="Killermanjarrrro";
dups_bitwise(A);

return 0;
}