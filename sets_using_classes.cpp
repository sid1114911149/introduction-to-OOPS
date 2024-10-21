#include<iostream>
using namespace std;
#define M 1000
class sets{
    int arr[M],size;
    public:
    sets(){
        size=-1;
        cout<<"a empty set is created\n";
    }
    sets(int a){
        size=-1;
        for(int i=1;i<=a;i++){
            insertSet(i);
        }
        cout<<"a set is initialised with first "<<a<<" natural numbers\n";
    }
    sets(const sets & x){
        size=-1;
        for(int i=0;i<=x.size;i++){
            insertSet(x.arr[i]);
        }
        cout<<"set is copied successfully\n";
    }
    ~sets(){
        cout<<"SET DESTRUCTED SUCCESSFULLY\n";
    }
    void print(){
        if(size==-1){
            cout<<"EMPTY SET\n";
            return ;
        }
        cout<<"{";
        for (int i=0;i<=size;i++){
            cout<<arr[i];
            if(i!=size){
            	cout<<",";
            }
        }
        cout<<"}\n";
    }
    int index(int a){
        if(size==-1){
            return -1;
        }
        int j=0;
        for(int i=0;i<=size;i++){
            if(arr[i]==a){
                 j=i;
            }
        }
        return j;
    }
    int ismemeber(int a){
        if(size==-1){
            return 0;
        }
        for(int i=0;i<=size;i++){
            if(arr[i]==a){
                return 1;
            }
        }
        return 0;
    }
    void insertSet(int a){
        if(size==-1){
            size++;
            arr[size]=a;
            return ;
        }
        if(ismemeber(a)){
            //cout<<a<<" is already memeber of the set\n";
            return ;
        }
        size++;
        arr[size]=a;
        return ;
    }
    void delSet(int a){
        if(!ismemeber(a)){
            cout<<a<<" is not found in the Set\n";
            return ;
        }
        int j=index(a);
        for(int i=j;i<=size;i++){
            arr[i]=arr[i+1];
        }
        size--;
        return ;
    }
    sets unions(const sets &s){
    	sets s1;
    	for(int i=0;i<=size+s.size+1;i++){
    		if(i<=size){
    			s1.insertSet(arr[i]);
    		}
    		else{
    			s1.insertSet(s.arr[i-size-1]);
    		}
    	}
    	return s1;
    }
    sets intersection(const sets &s){
    	sets s1;
    	for(int i=0;i<=size;i++){
    		for(int j=0;j<=s.size;j++){
    			if(arr[i]==s.arr[j]){
    				s1.insertSet(arr[i]);
    			}
    		}
    	}
    	return s1;
    }
};
void operate(sets &s){
    int ch=1,a;
    do{
        cout<<"ENTER\n1 FOR INSERTION\n2 FOR DLELETION\n3 FOR FINDING\n4 FOR DISPLAY\n5 FOR EXITING:";
        cin>>ch;
        switch(ch){
            case 1:cout<<"enter number to be inserted:";
                    cin>>a;
                    s.insertSet(a);
                    break;
            case 2:cout<<"enter number to be deleted:";
                    cin>>a;
                    s.delSet(a);
                    break;     
            case 3:cout<<"enter number to be searched:";
                    cin>>a;
                    if(s.ismemeber(a)){
                        cout<<a<<" is found in the set\n";
                    }else{
                        cout<<a<<" is not found in the set\n";
                    }
                    break;   
            case 4:s.print();
                    break;
            case 5:cout<<"EXITING...\n";
                    break; 
            default:cout<<"NO COMMAND FOUND\n";
                    break;                             
        }
    }while(ch!=5);
}
int main(void){
    int n;
    cout<<"ENTER N:";
    cin>>n;
    sets s1,s2(n);
    sets s3(s2),s4,s5;
    int ch;
    do{
        cout<<"want to perform any operations on the sets,if yes enter set no else enter 0:";
        cin>>ch;
        if(ch!=0){
            if(ch==1){
                operate(s1);
            }
            else if(ch==2){
                operate(s2);
            }
            else{
                operate(s3);
            }
        }    
    }while(ch!=0);
    s4=s1.unions(s2);
    s5=s1.intersection(s2);
    cout<<"SET 1:";
    s1.print();
    cout<<"SET 2:";
    s2.print();
    cout<<"SET 3(COPIED FROM SET 2):";
    s3.print();
    cout<<"UNION OF SET 1 AND SET 2:";
    s4.print();
    cout<<"INTERSECTION OF SET 1 AND SET 2:";
    s5.print();
    return 0;
}
