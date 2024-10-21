#include<stdio.h>
#include<stdlib.h>
#define M 100
struct queue{
    int arr[M],front,rear;
}c;
void create(){
    c.front=-1;
    c.rear=-1;
    printf("QUEUE created succesfully\n");
}
int isempty(){
    if(c.rear==-1){
        return 1;
    }
    return 0;
}
int isfull(){
    if(c.rear==M-1){
        return 1;
    }
    return 0;
}
void display(){
    if(isempty(c)){
        printf("QUEUE is empty\n");
        return;
    }
    for(int i=c.front;i<=c.rear;i++){
        printf("%d\t",c.arr[i]);
    }
    printf("\n");
}
void enqueue(){
    if(isfull(c)){
        printf("OVRFLOW\n");
        return;
    }
    int a;
    printf("enter element to be enqueued:");
    scanf("%d",&a);
    if(c.front==-1){
        c.front++;
    }
    c.rear++;
    c.arr[c.rear]=a;
}
int dequeue(){
    int a;
    if(isempty(c)){
        printf("UNDERFLOW\n");
    }
    else if(c.front==c.rear){
        a=c.arr[c.front];
        c.front=c.rear=-1;
    }
    else{
        a=c.arr[c.front];
        c.front++;
        printf("%d is dequeued\n",a);
        return a;
    }
}
int main(){
    int ch,a;
    do{
        printf("ENTER\n1 FOR CREATION\n2 FOR ENQUEUE\n3 FOR DEQUEUE\n4 FOR CHECKING ISEMPTY\n5 FOR CHECKING IS FULL\n6 FOR DISPLAY\n7 FOR EXITING:");
        scanf("%d",&ch);
        switch(ch){
            case 1:create();
                break;
            case 2:enqueue();
                break;
            case 3:dequeue();
                break;
            case 4:if(isempty()){
                        printf("QUEUE is empty\n");
                    }
                    else{
                        printf("QUEUE is not empty\n");
                    }
                break; 
            case 5:if(isfull()){
                        printf("QUEUE is full\n");
                    }
                    else{
                        printf("QUEUE is not full\n");
                    }
                break;   
            case 6:display();
                break;       
            case 7:printf("EXITING...\n");
                break;
            default: printf("NO COMMAND FOUND\n");
                break;   
        }
    }while(ch!=7);
    return 0;
}