#include<iostream>
#include<stdlib.h>
using namespace std;
class Stack{
private:
   string stck[20];
   int stop;
public:
	Stack(){
		stop=-1;
	}
   void push(string);
   string pop(void);
   void emptys(void);
   void display(void);
   string rettop(void);
};
void Stack::push(string item){
	if(item=="null"){
		return;
	}
	stop++;
	stck[stop]=item;
}
string Stack::pop(){
	string item;
	if(stop==-1){
		return "null";
	}
	item=stck[stop];
	stop--;
	return item;
}
void Stack::emptys(){
    stop=-1;
    return;
}
string Stack::rettop(){
	if(stop==-1){
		return "null";
	}
	return stck[stop];
} 
void Stack::display(){
	if(stop==-1){
		cout<<"\nStack is Empty";
		return;
	}
	else{
		cout<<"\nStack Contains : ";
		for(int i=0;i<=stop;i++){
			cout<<"\n"<<stck[i];
		}
	}
}
int main(){
	int ch;
	string add;
	string ret;
	Stack s1,s2;
	while (1){
		cout<<"\nEnter your choice: \n1. Enter a new address \n2. Undo\n3. Redo\n4. Display \n5. Clear\n6. Exit :";
		cin>>ch;
		switch(ch){
			case 1:
					cout<<"\nEnter the address :  ";
					cin>>add;
					s1.push(add);
					break;
			case 2:
					cout<<"\n Current location :  ";
					ret=s1.pop();
					s2.push(ret);
					ret=s1.rettop();
					cout<<ret;
					break;
			case 3:
					cout<<"\n Current location :  ";
					ret=s2.pop();
					s1.push(ret);
					cout<<ret;
					break;
			case 4: 
					cout<<"\nUndo Stack :";
					s1.display();
					cout<<"\nRedo Stack :";
					s2.display();
					break;
			case 5:
					cout<<"\nStacks are Emptied";
					s1.emptys();
					s2.emptys();
					break;
			default:
					cout<<"\nLeaving the Application\n";
					exit(1);
		}
	}



	return 0;

}

