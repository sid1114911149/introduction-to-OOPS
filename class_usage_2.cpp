//23CS8005
//PASHAM.SIDDARDHA REDDY
#include<iostream>
#include<string>
using namespace std;
class book{
	string title,author;
	int year;
	float cost,dcost;
	public:
	book(){
		cout<<"CLASS IS CREATED SUCCESSFULLY\n";
	}
	~book(){
		cout<<"CLASS IS DESTRUCTED SUCCESSFULLY\n";
	}
	void setdata(){
		cout<<"enter title of the book:";
		getline(cin,title);
		cout<<"enter the name of the author the book:";
		getline(cin,author);
		cout<<"enter the year of publication of the book:";
		cin>>year;
		cout<<"enter the cost of the book:";
		cin>>cost;		
	}
	void getdata(){
		cout<<"Title of the book:"<<title<<"\n";
		cout<<"Name of the author the book:"<<author<<"\n";
		cout<<"Year of publication of the book:"<<year<<"\n";
		cout<<"Cost of the book:"<<cost<<"\n";
	}
	void getdiscount(){
		float discount;
		cout<<"enter discount on the book:";
		cin>>discount;
		cost=cost*((100-discount)/100);
		cout<<"price of the book after applying discount is:"<<cost<<"\n";
	}	
};
int main(){
	book b;
	b.setdata();
	b.getdata();
	b.getdiscount();
	return 0;
}			
		
