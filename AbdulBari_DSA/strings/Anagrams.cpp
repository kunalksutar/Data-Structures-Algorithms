#include<iostream>
using namespace std;

void checkAnagram(char A[],char B[]){
    int hash[26]={0};
    for(int i=0;A[i]!='\0';i++){
        hash[A[i]-97]++;
    }

    for(int i=0;B[i]!='\0';i++){
        hash[B[i]-97]--;
        if(hash[B[i-97]]<0){
            cout<<"NOT an anagram."<<endl;
        }
    }

    cout<<"Are Anagrams."<<endl;

    
}

int main(){
    char A[]="decimal";
    char B[]="medical";
    checkAnagram(A,B);

return 0;
}