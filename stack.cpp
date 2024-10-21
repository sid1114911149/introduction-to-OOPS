//23CS8005
//PASHAM.SIDDARDHA REDDY
#include<iostream>
#include<stdlib.h>
using namespace std;
#define M 100
class stack{
    int arr[M],top;
    public:
    stack(){
    	cout<<"STACK CREATED SUCCESSFULLY"<<"\n";
    	top=-1;
    }
    ~stack(){
    	cout<<"STACK DESTRUCTED SUCCESSFULLY"<<"\n";
    }	
    int isempty(){
    	if(top==-1){
        	return 1;
    	}
 	return 0;
    }
    int isfull(){
        if(top==M-1){
            return 1;
        }
        return 0;
    }
    void push(int a){
    	if(isfull()){
    		cout<<"OVERFLOW\n";
    		return ;
    	}
    	top++;
    	arr[top]=a;		
    }
    void pop(){
    	if(isempty()){
        	cout<<"UNDERFLOW"<<"\n";
    	}
    	else{
    		int a=arr[top];
    		top--;
    		cout<<a<<" is popped"<<"\n";
    		//return a;
    	}
    }
    void display(){
        if(isempty()){
            cout<<"stack is empty\n";
            return;
        }
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<",";;
        }
        cout<<"\n";
    }
};
int main(){
    stack s;
    int ch,a;
    do{
        cout<<"ENTER\n1 FOR PUSHING\n2 FOR POPPING\n3 FOR CHECKING IS EMPTY\n4 FOR CHECKING IS FULL\n5 FOR DISPLAY\n6 FOR EXITING:";
        cin>>ch;
        switch(ch){
            case 1:cout<<"enter number to be inserted:";
            	   cin>>a;
            	   s.push(a);
                break;
            case 2:s.pop();
                break;
            case 3:if(s.isempty()){
                        cout<<"stack is empty\n";
                    }
                    else{
                        cout<<"stack is not empty\n";
                    }
                break; 
            case 4:if(s.isfull()){
                        cout<<"stack is full\n";
                    }
                    else{
                        cout<<"stack is not full\n";
                    }
                break;   
            case 5:s.display();
                break;       
            case 6:cout<<"EXITING...\n";
                break;
            default: cout<<"NO COMMAND FOUND\n";
                break;   
        }
    }while(ch!=6);
    return 0;
}
