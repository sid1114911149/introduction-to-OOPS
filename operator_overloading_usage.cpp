#include<iostream>
using namespace std;
class complex{
    float real,imag;
    public:
    complex(float a=0,float b=0){
        real=a;
        imag=b;
    }
    complex  operator +(const complex &c){
        complex c1;
        c1.real=real+c.real;
        c1.imag=imag+c.imag;
        return c1;
    }
    complex  operator -(const complex &c){
        complex c1;
        c1.real=real-c.real;
        c1.imag=imag-c.imag;
        return c1;
    }
    void print(){
        cout<<real<<"+"<<imag<<"i"<<"\n";
        return ;
    }
};
int main(void){
    complex c1(4,7),c2(87.4,76.276);
    complex c3=c1+c2;
    complex c4=c2-c1;
    cout<<"first complex number is:";
    c1.print();
    cout<<"second complex number is:";
    c2.print();
    cout<<"sum of the complex numbers is:";
    c3.print();
    cout<<"difference of the complex numbers is:";
    c4.print();
    return 0;
}
