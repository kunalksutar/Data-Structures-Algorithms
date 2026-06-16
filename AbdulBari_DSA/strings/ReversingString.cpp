#include<iostream>
using namespace std;

char reverse(char p[]){
    int length;
    for(length = 0 ; p[length]!='\0' ; length++){//finding the length of the string.
    }
    
    int j = length-1;//will start from the right side which is not a '\0'.
    for(int i=0; i<j ; i++){
        char temp = p[i];
        p[i]=p[j];
        p[j]=temp;
        j--;
    }
}

int main(){
char name[]="Killermanjaro";
cout<<name<<endl;
reverse(name);
cout<<name;
return 0;
}