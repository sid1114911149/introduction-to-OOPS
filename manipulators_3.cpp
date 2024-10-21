//NAME:P.SIDDARDHA REDDY
//ROLL NO:23CS8005
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    double itheta,ftheta,dtheta,a,b,c;
    cout<<"enter initial value of theta:";
    cin>>itheta;
    cout<<"enter final value of theta:";
    cin>>ftheta;
    cout<<"enter step count theta:";
    cin>>dtheta;
    a=10;
    b=0.1;
    c=0.5;
    cout<<setw(1)<<setfill('1');
    double theta=itheta;
    double x=a*exp(-b*theta)*cos(c*theta);
    double delta=(ftheta-itheta)/dtheta;
    for(int i=0;i<delta;i++){
        cout<<setw(40+x)<<setfill(' ')<<'*'<<'\n';
        theta+=dtheta;
        x=a*exp(-b*theta)*cos(c*theta);
    }
    return 0;
}