#include<iostream>
using namespace std;
class arthimetic{
    float a;
    public:
    arthimetic(float b=0){
        a=b;
    }
    arthimetic operator + (const arthimetic & b){
        arthimetic c;
        c.a=a+b.a;
        return c;
    }
    arthimetic operator - (const arthimetic & b){
        arthimetic c;
        c.a=a-b.a;
        return c;
    }
    arthimetic operator * (const arthimetic & b){
        arthimetic c;
        c.a=a*b.a;
        return c;
    }
    arthimetic operator / (const arthimetic & b){
        arthimetic c;
        c.a=a/b.a;
        return c;
    }
    void print(){
        cout<<a<<"\n";
        return ;
    }
};
int main(){
    arthimetic a1(5),a2(7),a3,a4,a5,a6;
    a3=a1+a2;
    a4=a1-a2;
    a5=a1*a2;
    a6=a1/a2;
    cout<<"first number is:";
    a1.print();
    cout<<"second number is:";
    a2.print();
    cout<<"sum of the given numbers is:";
    a3.print();
    cout<<"difference of the given numbers(first-second) is:";
    a4.print();
    cout<<"product of the given numbers is:";
    a5.print();
    cout<<"quotient of the given numbers(first/second) is:";
    a6.print();   
    return 0;
}
