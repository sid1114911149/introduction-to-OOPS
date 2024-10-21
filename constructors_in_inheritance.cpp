#include<iostream>
#include<cstdlib>
using namespace std;
class veichle{
    protected:
    int wheels,speed;
    public:
    veichle(int w=0,int s=0){
        wheels=w;
        speed=s;
    }
};
class truck;
class car:public veichle{
    private:
    int passengers;
    public:
    car(int w,int s,int p):veichle(w,s){
        passengers=p;
    }
    void display(){
        cout<<"no of wheels for the car is:"<<wheels<<endl;
        cout<<"speed of the car is:"<<speed<<" kmph"<<endl;
        cout<<"no of passengers can be seated inside the car is:"<<passengers<<endl;
    }
    friend void compare(const car &c,const truck &t);
};
class truck:public veichle{
    private:
    int load;
    public:
    truck(int w,int s,int p):veichle(w,s){
        load=p;
    }
    void display(){
        cout<<"no of wheels for the truck is:"<<wheels<<endl;
        cout<<"speed of the truck is:"<<speed<<" kmph"<<endl;
        cout<<"maximum load of the truck  is:"<<load<<" kg"<<endl;
    }
    friend void compare(const car &c,const truck &t);
};
void compare(const car &c,const truck &t){
    if(c.speed > t.speed){
        cout<<"car is faster\n";
    }else if(c.speed == t.speed){
        cout<<"both are of same speed\n";
    }else{
        cout<<"truck is faster\n";
    }
}
int main(void){
    veichle v;
    car c(4,240,6);
    truck t(12,160,60000);
    c.display();
    t.display();
    compare(c,t);
    return 0;
}