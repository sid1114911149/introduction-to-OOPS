#include<iostream>
using namespace std;
class coordinates{
    float  x,y;
    public:
    coordinates(float a=0,float b=0){
        x=a;
        y=b;
    }
    friend ostream &operator <<(ostream &os,const coordinates &s){
        os<<"("<<s.x<<","<<s.y<<")"<<endl;
        return os;
    }
    coordinates operator-(){
        static coordinates c;
        c.x=x;
        c.x--;
        c.y=y;
        c.y--;
        cout<<"AFTER APPLYING THE UNARY OPERATOR:"<<c;
        return c;
    }
};
int main(void){
    coordinates c1(2.34,5.89);
    cout<<"BEFORE APPLYING THE UNARY OPERATOR:"<<c1;
    -c1;
    return 0;
}
