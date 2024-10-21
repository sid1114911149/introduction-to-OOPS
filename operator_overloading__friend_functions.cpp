#include<iostream>
#include<algorithm>
using namespace std;
class fraction{
    int num,den;
    public:
    fraction(int a=0,int b=1){
        int k=__gcd(abs(a),abs(b));
        num=a/k;
        den=b/k;
    }
    fraction operator +(const fraction &b){
        int a,k;
        a=num*b.den+den*b.num;
        k=den*b.den;
        fraction c(a,k);
        return c;
    }
    fraction operator -(const fraction &b){
        int a,k;
        a=num*b.den-den*b.num;
        k=den*b.den;
        fraction c(a,k);
        return c;
    }
    fraction operator *(const fraction &b){
        int a,k;
        a=num*b.num;
        k=den*b.den;
        fraction c(a,k);
        return c;
    }
    fraction operator /(const fraction &b){
        int a,k;
        a=num*b.den;
        k=den*b.num;
        fraction c(a,k);
        return c;
    }
    void operator=(const fraction &b){
        num=b.num;
        den=b.den;
        return ;
    }
    friend ostream &operator<<(ostream &os,const fraction &b){
        os<<b.num<<"/"<<b.den;
        return os;
    }
    bool operator ==(const fraction &b){
        return num==b.num && den==b.den?true:false;
    }
    bool operator !=(const fraction &b){
        return num!=b.num || den!=b.den?true:false;
    }
    bool operator < (const fraction &b){
        float a=(float(num)/den),c=(float(b.num)/b.den);
        return a<c?false:true;
    }
};
int main(){
    fraction f1(6,32),f2(7,32),f3;
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
    f3=f2;
    cout<<"using assignment overloading(f3=f2):"<<f3<<endl;
    if(f1!=f2){
        cout<<f1<<" is not equal to "<<f2<<endl;
    }
    if(f1==f2){
        cout<<f1<<" is equal to "<<f2<<endl;
    }
    if(f1<f2){
        cout<<f1<<" is greater than "<<f2<<endl;
    }else{
        cout<<f1<<" is less than "<<f2<<endl;
    }
    return 0;
}
