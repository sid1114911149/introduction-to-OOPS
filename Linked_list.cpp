#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
}*head,*tail,*temp,*temp2,*temp3,*head2;
node * print(node *temp){
    while(temp!=NULL){
        cout<<temp->data<<'\t';
        temp=temp->next;
    }       cout<<"\n";
}
node *insert(){
    temp=(node*)malloc(sizeof(node));     
    cout<<"enter the value:";
    cin>>temp->data;
    temp->next=NULL;
    return temp;
}
node *create(node* temp){
    if(temp==NULL){
        temp=insert();
    }
    else if(temp!=NULL){
        temp->next=create(temp->next);
    }
    else {
        return NULL;
    }
}
node *insertion(node *temp){
    if(temp==NULL){
        temp=insert();
    }
    else{
        int pos;
        cout<<"enter position of insertion:";
        cin>>pos;
       temp2=temp;
        if(pos==1){
            temp2=insert();
            temp2->next=head;
            head=temp2;
        }
        else{
            for(int i=1;i<pos-1;i++){
                temp2=temp2->next;
            }
            temp3=insert();
            temp3->next=temp2->next;
            temp2->next=temp3;
        }
    }
    print(head);
}
node *deletion(node *temp){
     if(temp==NULL){
        cout<<"UNDERFLOW\n";
    }
    else{
        int pos;
        cout<<"enter position of deletion:";
        cin>>pos;
       temp2=temp;
        if(pos==1){
            head=head->next;
            temp->next=NULL;
        }
        else{
            for(int i=1;i<pos-1;i++){
                temp=temp->next;
                temp2=temp->next;
            }
            temp->next=temp2->next;
            temp2->next=NULL;
        }
    }
    print(head);
}
void searching(node *temp,int d){
    if(temp!=NULL){
        if(temp->data==d){
                cout<<d<<" is present in the list\n";
            }
        else{
            searching(temp->next,d);
        }
    }
    else{
         cout<<"NOT FOUND\n";
    }
}
node *concat(node *temp){
    cout<<"enter second list to concat:\n";
    int ch=1;
    while(ch){
        if(head2==NULL){
            head2=create(head2);
        }
        else{
            create(head2);
        }
        cout<<"enter 1 or 0 to continue:";
        cin>>ch;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    print(head);
}
int main()
{
    int ch=1,d;
    while(ch){
        if(head==NULL){
            head=create(head);
        }
        else{
            create(head);
        }
        cout<<"enter 1 or 0 to continue:";
        cin>>ch;
    }    
    do{     
        cout<<"ENTER \n1 FOR DISPLAY\n2 FOR INSERTION\n3 FOR DELETION\n4 FOR CONCATENATION\n5 FOR SEARCHING\n6 FOR EXITING:";
        cin>>ch;
        switch(ch){
        case 1:print(head);
               break;
        case 2:insertion(head);
               break;
        case 3:deletion(head);
               break;
        case 4:concat(head);
               break;
        case 5:int d;
                cout<<"enter number to be searched:";
                cin>>d;
                searching(head,d);
                break;
        case 6:cout<<"exiting...";
               break;       
        default:cout<<"NO COMMAND FOUND\n";
               break;        
    }
    }while(ch!=6);
    return 0;
}