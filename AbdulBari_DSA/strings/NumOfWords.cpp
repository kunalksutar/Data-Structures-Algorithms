#include<iostream>
using namespace std;

int main(){
char greet[]="how are    you there";
int num_words=1;//assuming the list is not empty.
for(int i=0;greet[i]!='\0';i++){
    if(greet[i]==' ' && greet[i-1]!=' '){
        num_words++;
    }
}

cout<<num_words;
return 0;
}