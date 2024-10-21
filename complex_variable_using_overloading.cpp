#include<iostream>
using namespace std;
class complex{
    float real,imag;
    public :
    complex(float a=0,float b=0){
        imag=a;
        real=b;
    }
    complex operator+(const complex &b ){
        complex a;
        a.real=real+b.real;
        a.imag=imag+b.imag;
        return a;
    }
    complex operator-(const complex &b ){
        complex a;
        a.real=real-b.real;
        a.imag=imag-b.imag;
        return a;
    }
    complex operator *(const complex &b){
        complex a;
        a.real=real*b.real-imag*b.imag;
        a.imag=real*b.imag+imag*b.real;
        return a;
    }
    complex operator /(const complex &b){
        complex a;
        a.real=(real*b.real+imag*b.imag)/(b.real*b.real+b.imag*b.imag);
        a.imag=(real*b.imag-imag*b.real)/(b.real*b.real+b.imag*b.imag);
        return a;
    }
    void operator =(const complex &b ){
        real=b.real;
        imag=b.imag;
        return ;
    }
    friend complex operator !(const complex &b){
        complex a;
        a.real=b.real;
        a.imag=-b.imag;
        return a;
    }
    friend ostream &operator<<(ostream &os,const complex &b){
        if(b.imag<0){
            os<<b.real<<" "<<b.imag<<"i";
        }else{
            os<<b.real<<" + "<<b.imag<<"i";
        }
        return os;
    }
    bool operator==(const complex &b){
        return real==b.real && imag==b.imag?true:false;
    }
    bool operator!=(const complex &b){
        return real!=b.real || imag!=b.imag?true:false;
    }
};  
int main(){
    complex f1(6.7,8.34),f2(7.32,-6),f3;
    cout<<"f1 is ="<<f1<<endl;
    cout<<"f2 is ="<<f2<<endl;
    f3=f1+f2;
    cout<<"f1+f2="<<f3<<endl;
    f3=f1-f2;
    cout<<"f1-f2="<<f3<<endl;
    f3=f1*f2;
    cout<<"f1*f2="<<f3<<endl;
    f3=f1/f2;
    cout<<"f1/f2="<<f3<<endl;
    f3=!f1;
    cout<<"conjugate of "<<f1<<" is "<<f3<<endl;
    if(f1!=f2){
        cout<<f1<<" is not equal to "<<f2<<endl;
    }else{
        cout<<f1<<" is equal to "<<f2<<endl;
    }
    if(f1==f2){
        cout<<f1<<" is equal to "<<f2<<endl;
    }else{
        cout<<f1<<" is not equal to "<<f2<<endl;
    }
    f3=f2;
    cout<<"using assignment overloading(f3=f2):"<<f3<<endl;
    return 0;
}