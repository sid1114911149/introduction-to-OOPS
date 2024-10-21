#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
}*temp;
struct node* newnode(int d){
    node *temp=new (node);
    temp->next=NULL;
    temp->data=d;
    return temp;
}
class List{
    private:
    node *head,*tail;
    public:
    List(){
        head=nullptr;
        tail=head;
    }
    List(const List &l):head(nullptr),tail(nullptr){
        temp=l.head;
        while(temp!=NULL){
            if(head==NULL){
                head=newnode(temp->data);
                tail=head;
            }else{
                tail->next=newnode(temp->data);
                tail=tail->next;
            }
            temp=temp->next;
        }
    }
    friend istream &operator>>(istream &cin,List &l){
        int d;
        cout<<"enter value:";
        cin>>d;
        if(l.head==NULL){
            l.head=newnode(d);
            l.tail=l.head;
        }else{
            l.tail->next=newnode(d);
            l.tail=l.tail->next;
        }
    }
    friend ostream &operator<<(ostream &os,const List &l){
        temp=l.head;
        while(temp!=NULL){
            os<<temp->data<<" ";
            temp=temp->next;
        }
        os<<"\n";
        return os;
    }
    List operator+(List &l){
        List l1;
        l1.head=head;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=l.head;
        return l1;
    }
    List operator!(){
        List result;
        struct node* current = head;
        while (current != nullptr) {
            struct node* newNode = newnode(current->data);
            newNode->next = result.head;
            result.head = newNode;
            current = current->next;
        }
        return result;
    }
    bool operator==(const List &l){
        struct node *temp,*temp2;
        temp=head;
        temp2=l.head;
        while(temp!=NULL && temp2!=NULL){
            if(temp->data!=temp2->data){
                return false;
            }
            temp=temp->next;
            temp2=temp2->next;
        }
        if((temp==NULL && temp2!=NULL)||(temp!=NULL && temp2==NULL)){
            return false;
        }
        return true;
    }
    void operator=(const List &l){
        temp=l.head;
        while(temp!=NULL){
            if(head==NULL){
                head=newnode(temp->data);
                tail=head;
            }else{
                tail->next=newnode(temp->data);
                tail=tail->next;
            }
            temp=temp->next;
        }
    }
    void operator[](int index){
        temp=head;
        int i=0;
        while(temp!=NULL){
            if(i==index){
                cout<<"ELEMENT AT INDEX "<<index<<" IS "<<temp->data<<endl;
                return ;
            }
            i++;
            temp=temp->next;
        }
        cout<<"INDEX OUT OF RANGE...\n";
        return ;
    }
};
int main(void){
    List l1,l2;
    int ch=1,d;
    cout<<"enter list 1:\n";
    while(ch){
        cin>>l1;
        cout<<"enter 0 or 1 to continue:";
        cin>>ch;
    }
    cout<<"enter list 2:\n";
    ch=1;
    while(ch){
        cin>>l2;
        cout<<"enter 0 or 1 to continue:";
        cin>>ch;
    }
    cout<<"LIST 1:  "<<l1<<"LIST 2:  "<<l2;
    List l3(l1);
    cout<<"USING COPY CONSTRUCTOR COPYING LIST 1 TO LIST 3\n";
    cout<<"LIST 3:  "<<l3;
    cout<<"AFTER CONCATINATING LIST 1 AND LIST 2:  ";
    cout<<l1+l2;
    cout<<"AFTER REVERSING LIST 1:  ";
    cout<<!l1;
    if(l1==l2){
        cout<<"LIST 1 AND LIST 2 ARE EQUAL\n";
    }else{
        cout<<"LIST 1 AND LIST 2 ARE NOT EQUAL\n";
    }
    cout<<"BY OVERLOADING ASSIGNMENT OPERATOR:     ";
    List l4=l2;
    cout<<"LIST 4:  "<<l4;
    cout<<"FINDING ELEMENT AT INDEX 3 of list 1\n";
    l1[3];
    cout<<"FINDING ELEMENT AT INDEX 9 if list 1\n";
    l1[9];
    return 0;
}
