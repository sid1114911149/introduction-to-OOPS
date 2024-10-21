//23CS8005
//PASHAM.SIDDARDHA REDDY
#include<iostream>
#include<stdlib.h>
using namespace std;
#define M 100
class queue{
    int arr[M],front,rear;
    public:
    queue(){
    	cout<<"QUEUE IS CREATED SUCCESSFULLY\n";
    	front=-1;
    	rear=-1;
    }
    ~queue(){
    	cout<<"QUEUE IS DESTRUCTED SUCCESSFULLY\n";
    }
    int isempty(){
    	if(rear==-1){
        	return 1;
    	}
	return 0;
    }
    int isfull(){
    	if(rear==M-1){
        	return 1;
    	}
    	return 0;
    }
    void enqueue(int a){
    	if(isfull()){
        	cout<<"OVRFLOW\n";
        	return;
    	}
    	if(isempty()){
        	front++;
    	}
    	rear++;
    	arr[rear]=a;
    }
    void dequeue(){
    	int a;
    	if(isempty()){
        	cout<<"UNDERFLOW\n";
    	}
    	else if(front==rear){
        	a=arr[front];
        	front=rear=-1;
    	}
    	else{
        	a=arr[front];
        	front++;
        	cout<<a<<" is dequeued\n";
        	//return a;
    	}
    }
    void display(){
    	if(isempty()){
        	cout<<"QUEUE is empty\n";
        	return;
    	}
    	for(int i=front;i<=rear;i++){
        	cout<<arr[i]<<",";
    	}
    	cout<<"\n";
    }
};
int main(){
    queue q;
    int ch,a;
    do{
        cout<<"ENTER\n1 FOR ENQUEUE\n2 FOR DEQUEUE\n3 FOR CHECKING IS EMPTY\n4 FOR CHECKING IS FULL\n5 FOR DISPLAY\n6 FOR EXITING:";
        cin>>ch;
        switch(ch){
            case 1:cout<<"enter element to be enqueued:";
    		   cin>>a;
                   q.enqueue(a);
                break;
            case 2:q.dequeue();
                break;
            case 3:if(q.isempty()){
                        cout<<"QUEUE is empty\n";
                    }
                    else{
                        cout<<"QUEUE is not empty\n";
                    }
                break; 
            case 4:if(q.isfull()){
                        cout<<"QUEUE is full\n";
                    }
                    else{
                        cout<<"QUEUE is not full\n";
                    }
                break;   
            case 5:q.display();
                break;       
            case 6:cout<<"EXITING...\n";
                break;
            default:cout<<"NO COMMAND FOUND\n";
                break;   
        }
    }while(ch!=6);
    return 0;
}
