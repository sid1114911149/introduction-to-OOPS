#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
class node{
    public:
    int data;
    class node * next;
}*arr1[10],*temp,*temp2;
void print(node *temp,int b){
    if(temp==NULL){
        cout<<"NULL\n";
        return;
    }
    cout<<b;
    while(temp!=NULL){
        cout<<"-->"<<temp->data;
        temp=temp->next;
    }
    cout<<"\n";
}
node *insert(int d){
        node* temp=new node();
        temp->next=NULL;
        temp->data=d;
        return temp;
    }
node *create(class node *temp,int d){
        if(temp==NULL){
            temp=insert(d);
        }
        else if(temp!=NULL){
            temp->next=create(temp->next,d);
        }
            return temp;
    }
node *create1(int d,int b){
        if(arr1[d]==NULL){
                arr1[d]=create(arr1[d],b);
        }
        else{
                create(arr1[d],b);
        }
}
int check(int arr[],int n,int a){
    for(int i=0;i<n;i++){
        if(arr[i]==a){
            return 0;
        }
    }
    return 1;
}
int hfunction(int a){
    return a%10;
}
void hashfunction(int a){
        int b=a;
        a=b%(10);
        switch(a){
            case 0:create1(0,b);
                    break;
            case 1:create1(1,b);
                    break;
            case 2:create1(2,b);
                    break;
            case 3:create1(3,b);
                    break;        
            case 4:create1(4,b);
                    break;
            case 5:create1(5,b);
                    break;
            case 6:create1(6,b);
                    break;
            case 7:create1(7,b);
                    break;
            case 8:create1(8,b);
                    break;
            case 9:create1(9,b);
                    break;
            default:cout<<"hello\n";
                break;                                                                               
        }
}
int search(int a){
    int b;
    b=hfunction(a);
    temp=arr1[b];
    while(temp!=NULL){
        if(temp->data==a){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
void insertion(int a){
    int b;
    b=hfunction(a);
    create1(b,a);
}
void deletion(int a){
    int b;
    b=hfunction(a);
    if(arr1[b]==NULL|| !search(a)){
        cout<<"NOTHING TO DEELETE\n";
        return;
    }
    temp=arr1[b];
    temp2=temp;
    while(temp2->data!=a){
        temp=temp->next;
        temp2=temp->next;
    }
    temp->next=temp2->next;
    temp2->next=NULL;
}
void display(){
    print(arr1[0],0);
    print(arr1[1],1);
    print(arr1[2],2);
    print(arr1[3],3);
    print(arr1[4],4);
    print(arr1[5],5);
    print(arr1[6],6);
    print(arr1[7],7);
    print(arr1[8],8);
    print(arr1[9],9);
}
int main(){
    int arr[100],a,s;
    for(int i=0;i<100;){
        a=rand()%2000;
        if(check(arr,i,a)){
            arr[i]=a;
            i++;
        }
    }
    for(int i=0;i<100;i++){
        hashfunction(arr[i]);
    }
    do{
        cout<<"ENTER\n1 FOR SEARCHING\n2 FOR INSERTION\n3 FOR DELETION\n4 FOR DISPLAY\n5 FOR EXITING:";
        cin>>s;
        switch(s){
            case 1: cout<<"enter the number to be searched:";
                    cin>>a;
                    if(search(a)){
                        cout<<a<<" is found in the list\n";
                    }
                    else{
                        cout<<a<<" is not found in the list\n";
                    }
                    break;
            case 2:cout<<"ENTER THE NUMBER TO BE INSERTED:";
                    cin>>a;
                    insertion(a);
                    break;
            case 3:cout<<"ENTER THE NUMBER TO BE DELETED:";
                    cin>>a;  
                    deletion(a);
                    break; 
            case 4:display();
                    break;
            case 5: cout<<"EXITING...\n";
                    break;
            default:cout<<"NO COMMAND FOUND\n";
                    break;                                  
        }
    }while(s!=5);
    return 0;
}
