//NAME:P.SIDDARDHA REDDY
//ROLL NO:23CS8005
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n,m;
    cout<<"enter n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        m=2*(n-i);
        cout<<setw(i)<<setfill('*')<<""<<setw(m+1)<<setfill(' ')<<""<<setw(i+1)<<setfill('*')<<"\n";
    }
    for(int i=n-1;i>=1;i--){
        m=2*(n-i);
        cout<<setw(i)<<setfill('*')<<""<<setw(m+1)<<setfill(' ')<<""<<setw(i+1)<<setfill('*')<<"\n";
    }
    return 0;
}