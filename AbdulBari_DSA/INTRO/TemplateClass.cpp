#include<iostream>
using namespace std;

template<class T>
class Arithmetic{
    private:
        T a;
        T b;
    public:
        Arithmetic(T a,T b);//we will first have to write the functions here in public section.
        //only then we can write the functions somwhere outside the class.
        T add();
        T sub();
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b){
            this->a=a;
            this->b=b;
        }
template<class T>
T Arithmetic<T>::add(){
            T c;
            c=a+b;
            return c;
        }
template<class T>
T Arithmetic<T>::sub(){
            T c;
            c=a-b;
            return c;
        }

int main(){
    Arithmetic<int> arth(10,7);
    cout<<"add: "<<arth.add()<<endl;
    cout<<"sub: "<<arth.sub()<<endl;

    int a[5]={3,4,5,6,7};
    a[100]=44;
    cout<<a[100];
return 0;
}