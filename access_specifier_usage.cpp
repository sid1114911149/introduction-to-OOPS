#include<iostream>
#include<math.h>
using namespace std;
class circle{
    private:
    float radius;
    public:
    float calarea(){
        cout<<"enter radius:";
        cin>>radius;
        float area=3.14*radius*radius;
        return area;
    }
    float calcircum(){
        float cir=2*3.14*radius;
        return cir;
    }
};
int main(){
    class circle c;
    float f=c.calarea();
    cout<<"area of the cicle is:"<<f<<endl;
    f=c.calcircum();
    cout<<"circumference of the cicle is:"<<f<<endl;
    return 0;
}