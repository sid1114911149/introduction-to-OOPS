#include<iostream>
using namespace std;
class increment{
    int num;
    public:
    increment(int a=0){
        num=a;
    }
    friend ostream &operator<<(ostream &os,const increment &b){
        os<<b.num<<endl;
        return os;
    }
    increment operator++(){
        //++num;
        cout<<"while pre incrementing:"<<++num<<endl;
        cout<<"after pre incrementing:"<<num<<endl;
        return *this;
    }
    friend increment &operator++(increment &b,int dummy){
        cout<<"while post incrementing:"<<b.num++<<endl;
        cout<<"after post incrementing:"<<b.num<<endl;
        return b;
    }   
};
int main(void){
    increment a(10),c(5);
    cout<<"initial value of c is:"<<c;
    ++c;
    cout<<"initial value of a is:"<<a;
    a++;
    return 0;
}
