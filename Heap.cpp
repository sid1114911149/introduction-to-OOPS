#include<iostream>
using namespace std;
class heap{
    public:
    heap(){
        cout<<"HEAP IS CREATED\n";
    }
    int arr[100],size=0;
    void insert(int a){
        size+=1;
        arr[size]=a;
        int index=size;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(&arr[index],&arr[parent]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void swap(int *a,int *b){
        int t=*a;
        *a=*b;
        *b=t;
    }
    void print(){
        if(size==0){
            cout<<"HEAP IS EMPTY\n";
            return;
        }
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<"\n";
    }
    void arrange(int index){
        if(index<size && 2*index+1<=size){
            if(arr[index]<arr[2*index]){
                swap(&arr[index],&arr[2*index]);
            }
            if(arr[index]<arr[2*index+1]){
                swap(&arr[index],&arr[2*index+1]);
            }
            arrange(2*index);
        }
    }
    int check(){
        if(size==0){
            cout<<"NOTHING TO DELETE\n";
            return 0;
        }
        return 1;
    }
    void delmax(){
        if(!check()){
            return;
        }
        arr[1]=arr[size];
        size--;
        arrange(1);
        print();
    }
    void delmin(){
        if(!check()){
            return;
        }
        int small=arr[1],j=1;
        for(int i=2;i<=size;i++){
            if(small>arr[i]){
                j=i;
            }
        }
        arr[j]=arr[size];
        size--;
        arrange(1);   
        print(); 
    }
    void fmax(){
        if(!check()){
            cout<<"HEAP IS EMPTY\n";
            return;
        }
        cout<<"MAXIMUM ELEMENT IS "<<arr[1]<<'\n';
    }
    void fmin(){
        if(!check()){
            cout<<"HEAP IS EMPTY\n";
            return;
        }
        int small=arr[1];
        for(int i=2;i<=size;i++){
            if(small>arr[i]){
                small=arr[i];
            }
        }
        cout<<"MINIMUM ELEMENT IS "<<small<<'\n';
    }
    void replace(){
        if(!check()){
            cout<<"HEAP IS EMPTY\n";
            return;
        }
        int a,n,count=0;
        cout<<"enter element to be replaced:";
        cin>>a;
        cout<<"enter new element:";
        cin>>n;
        for(int i=1;i<=size;i++){
            if(arr[i]==a){
                swap(&arr[i],&n);
                count++;
            }
        }
        if(count==0){
            cout<<"ELEMENT IS NOT FOUND\n";
        }
    }
};
int main(){
    heap h;
    int n,a,count=0;
    do{
        cout<<"ENTER\n1 FOR INSERTION\n2 FOR DELETE MAXIMUM\n3 FOR DELETE MINIMUM\n4 FOR FIND MAXIMUM\n5 FOR FIND MINIMUM\n6 FOR REPLACE\n7 FOR DISPLAYING\n8 FOR EXITING:";
        cin>>n;
        switch(n){
            case 1:cout<<"enter value:";
                    cin>>a;     
                    h.insert(a);
                    break;
            case 2:h.delmax();
                    break;
            case 3:h.delmin();
                    break;        
            case 4:h.fmax();
                    break;
            case 5:h.fmin();
                    break;   
            case 6:h.replace();
                    break; 
            case 7:h.print();
                    break;        
            case 8:cout<<"EXITING";
                    break;
            default:cout<<"NO COMMNAND FOUND\n";
                    break;                           
        }
    }while(n!=8);
    return 0;
}