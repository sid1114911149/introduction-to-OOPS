//NAME:P.SIDDARDHA REDDY
//ROLL NO:23CS8005
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n,a;
    cout<<"enter n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        a=i-1;
       cout<<setw(a+1)<<setfill(' ');
        for(int j=i;j<=n;j++){
            cout<<j;
        }
        for(int j=n-1;j>=i;j--){
            cout<<j;
        }
        cout<<"\n";
    }
    for(int i=n-1;i>0;i--){
        a=i-1;
        cout<<setw(a+1)<<setfill(' ');
        for(int j=i;j<=n;j++){
            cout<<j;
        }
        for(int j=n-1;j>=i;j--){
            cout<<j;
        }
        cout<<"\n";
    }
    return 0;
}