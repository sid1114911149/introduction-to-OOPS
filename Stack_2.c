#include<stdio.h>
#include<stdlib.h>
#define M 100
struct stack{
    int arr[M],top;
}c;
void create(){
    c.top=-1;
    printf("stack created succesfully\n");
}
int isempty(){
    if(c.top==-1){
        return 1;
    }
    return 0;
}
int isfull(){
    if(c.top==M-1){
        return 1;
    }
    return 0;
}
void display(){
    if(isempty(c)){
        printf("stack is empty\n");
        return;
    }
    for(int i=c.top;i>=0;i--){
        printf("%d\t",c.arr[i]);
    }
    printf("\n");
}
void push(){
    if(isfull(c)){
        printf("OVRFLOW\n");
        return;
    }
    int a;
    printf("enter element to be pushed:");
    scanf("%d",&a);
    c.top++;
    c.arr[c.top]=a;
}
int pop(){
    if(isempty(c)){
        printf("UNDERFLOW\n");
    }
    else{
    int a=c.arr[c.top];
    c.top--;
    printf("%d is popped\n",a);
    return a;
    }
}
int main(){
    int ch,a;
    do{
        printf("ENTER\n1 FOR CREATION\n2 FOR PUSHING\n3 FOR POPPIING\n4 FOR CHECKING ISEMPTY\n5 FOR CHECKING IS FULL\n6 FOR DISPLAY\n7 FOR EXITING:");
        scanf("%d",&ch);
        switch(ch){
            case 1:create();
                break;
            case 2:push();
                break;
            case 3:pop();
                break;
            case 4:if(isempty()){
                        printf("stack is empty\n");
                    }
                    else{
                        printf("stack is not empty\n");
                    }
                break; 
            case 5:if(isfull()){
                        printf("stack is full\n");
                    }
                    else{
                        printf("stack is not full\n");
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