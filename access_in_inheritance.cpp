#include<iostream>
#include<string>
using namespace std;
class person{
    protected:
    string name;
    int age;
    public:
    person(string n,int a){
        name=n;
        age=a;
    }
    void display(){
        cout<<"NAME OF THE PERSON:"<<name<<endl;
        cout<<"AGE OF THE PERSON:"<<age<<endl;
    }
};
class student:public person{
    private:
    string studentid;
    public:
    student(string n,int a,string s):person(n,a){
        studentid=s;
    }
    void display(){
        cout<<"NAME OF THE STUDENT:"<<name<<endl;
        cout<<"AGE OF THE STUDENT:"<<age<<endl;
        cout<<"ID OF THE STUDENT:"<<studentid<<endl;
    }
};
int main(void){
    person p("siddardha",17);
    student s("rajesh",20,"23cs8008");
    p.display();
    s.display();
    return 0;
}