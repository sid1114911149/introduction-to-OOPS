//23CS8005
//PASHAM.SIDDARDHA REDDY
#include<iostream>
using namespace std;
class total_cost{
	float length,breadth,height,tcost,cost,dlength,dbreadth,wlength,wbreadth,tarea,area,warea,darea;
	public:
	total_cost(){
		cout<<"CLASS IS CREATED SUCCESSFULLY\n";
	}
	~total_cost(){
		cout<<"CLASS IS DESTRUCTED SUCCESSFULLY\n";
	}
	void setdata(){
		darea=0;
		warea=0;
		cout<<"enter breadth of the wall:";
		cin>>breadth;
		cout<<"enter length of the wall:";
		cin>>length;
		cout<<"enter height of the wall:";
		cin>>height;
		cout<<"enter cost for square meter:";
		cin>>cost;
		area=2*(length*height+breadth*height)+length*breadth;
		int a;
		cout<<"is there any door to wall,enter 1 if there else 0:";
		cin>>a;
		if(a!=0){
			cout<<"enter no of doors:";
			cin>>a;
			cout<<"enter breadth of each door:";
			cin>>dbreadth;
			cout<<"enter length of each door:";
			cin>>dlength;
			darea=a*dlength*dbreadth;
		}
		cout<<"is there any window to wall,enter 1 if there else 0:";
		cin>>a;
		if(a!=0){
			cout<<"enter no of windows:";
			cin>>a;
			cout<<"enter breadth of each window:";
			cin>>wbreadth;
			cout<<"enter length of each window:";
			cin>>wlength;
			warea=a*wlength*wbreadth;
		}
	}
	float getcost(){
		tarea=area-darea-warea;
		tcost=cost*tarea;
		return tcost;
	}	
};
int main(){
	total_cost w;
	w.setdata();
	cout<<"COST FOR PAINTING THE WALL IS:"<<w.getcost()<<endl;	
	return 0;
}			
		
