#include<iostream>
using namespace std;
class dimension{
    float length,breadth;
    public:
    dimension(){
    	length=0;
    	breadth=0;
    	cout<<"a point is created\n";
    }
    dimension(float a){
        length=a;
        breadth=a;
        cout<<"a square is created\n";
    }
    dimension(float a,float b){
        length=a;
        breadth=b;
        cout<<"a rectangle is created\n";
    }
    float area(){
        return length*breadth;
    }
    float perimeter(){
        return 2*(length+breadth);
    }
    ~dimension(){
    	if(length==breadth && breadth==0)
    	    cout<<"destructing the point\n";
        else if(length==breadth && breadth!=0)
            cout<<"destructing the square\n";
        else
            cout<<"destructing the rectangle\n";    
    }
};
int main(void){
    dimension square(5),rectangle(2,3),point;
    cout<<"area of the square is :"<<square.area()<<"\n";
    cout<<"perimeter of the square is :"<<square.perimeter()<<"\n";
    cout<<"area of the rectangle is :"<<rectangle.area()<<"\n";
    cout<<"perimeter of the rectangle is :"<<rectangle.perimeter()<<"\n";
    return 0;
}
