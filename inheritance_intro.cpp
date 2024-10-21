#include<iostream>
#include<cstdlib>
using namespace std;
class matrix{
   protected:
   int arr[3][3];
    public:
    void setdata(){
        cout<<"enter elements as row-major representation:";
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                scanf("%d",&arr[i][j]);
            }
        }
    }
    void display(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};
class matrixa:public matrix{
    
};
class matrixb:public matrixa{
    
};
int main(void){
    matrix M;
    matrixa A;
    matrixb B;
    cout<<"READING MATRIX 1:"<<endl;
    M.setdata();
    cout<<"READING MATRIX 2:"<<endl;
    A.setdata();
    cout<<"READING MATRIX 3:"<<endl;
    B.setdata();
    cout<<"MATRIX M:\n";
    M.display();
    cout<<"MATRIX A:\n";
    A.display();
    cout<<"MATRIX B:\n";
    B.display();
    return 0;
}