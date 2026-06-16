#include<iostream>
#define SIZE 10
using namespace std;

int hashFunction(int key){return key%SIZE;}
int probe(int H[],int key){
    int index=hashFunction(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)i++;
    return (index+i)%SIZE;
}

void insert(int H[],int key){
    int index=hashFunction(key);

    if(H[index]!=0){//meaning the position is already taken.
        index=probe(H,key);
    }
    H[index]=key;
}   

int main(){

    int H[SIZE];
    for(int i=0;i<SIZE;i++)H[i]=0;//setting initially everything to 0.

    insert(H,19);
    insert(H,22);
    insert(H,79);
    insert(H,69);

return 0;
}