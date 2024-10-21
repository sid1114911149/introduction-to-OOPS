//NAME:P.SIDDARDHA REDDY
//ROLL NO:23CS8005
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n,a;
    cout<<"enter n(must be odd):";
    cin>>n;
    for(int i=0;i<n/2+1;i++){
        a=n-2*i-1;
        cout<<setw(a+1)<<setfill(' ');
        for(int j=2*i+1;j>=1;j--){
            cout<<j;
        }
        for(int j=2;j<=2*i+1;j++){
            cout<<j;
        }
        cout<<"\n";
    }
    for(int i=n/2-1;i>=0;i--){
        a=n-2*i-1;
        cout<<setw(a+1)<<setfill(' ');
        for(int j=2*i+1;j>=1;j--){
            cout<<j;
        }
        for(int j=2;j<=2*i+1;j++){
            cout<<j;
        }
        cout<<"\n";
    }
    return 0;
}