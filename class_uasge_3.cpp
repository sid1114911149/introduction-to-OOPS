#include<iostream>
#include<math.h>
#include<string>
using namespace std;
class car{
    string  company,model;
    int year;
    public:
    class car setdata(){
        cout<<"enter company name:";
        getline(cin,company);
        cout<<"enter model name:";
        getline(cin,model);
        cout<<"enter year of manufacture:";
        cin>>year;
    }
    class car getdata(){
        int ch;
        cout<<"enter 1 for company name\n2 for model name\n3 for manufacturing year\n4 for total details:";
        cin>>ch;
        switch(ch){
            case 1:cout<<"NAME OF THE COMPANY IS:"<<company<<endl;
                break;
            case 2:cout<<"NAME OF THE MODEL IS:"<<model<<endl;
                break;
            case 3:cout<<"YEAR OF MANUFACTURING IS:"<<year<<endl;
                break;
            case 4:cout<<"NAME OF THE COMPANY IS:"<<company<<endl;
                   cout<<"NAME OF THE MODEL IS:"<<model<<endl;
                   cout<<"YEAR OF MANUFACTURING IS:"<<year<<endl;
                break;
            default:cout<<"No COMMAND FOUND"<<endl;
                break;                
        }
    }
};
int main(){
    class car c;
    c.setdata();
    c.getdata();
    return 0;
}