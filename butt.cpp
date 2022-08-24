#include<iostream>
#include <String>
using namespace std;
class state{
	public:
	state(int data, string ide){
		val = data;
		statide = ide;
		next = NULL;
	}
	string statide;
	int val;
	state * next;

};

class heristic
{
	
	int gn[20];
	double huer[20];
private:
	state * head;
	state * tail;

public:
	heristic(){
		head = NULL;
		tail = NULL;
	}
	void add(string ide,int value){
		if (head == NULL)
		{
			head = new state(value,ide);
			tail = head;
		}else{
			tail->next = new state(value,ide);
			tail = tail->next;
		}
	}
	
	void addgn(int statgn, int index){
		gn[index]	= statgn;
	}
		
	void calculat(){
		state * temp = head;
		int count = 0;
		int p = 0;
		while(temp != NULL){
			huer[count] = temp->val + gn[p];
			temp = temp->next;
			count++;
			p++;
		}
		state * itor = head;
		while(itor != NULL){
			cout << itor->statide<< "-";
			itor = itor->next;
		}
	}
	
};
int main()
{
	heristic * list = new heristic();
	string id;
	int value = 0;
	int gn;
	
	cout<<"stat 1"<<endl;
	cin>>id;
	cout<<"Value 1"<<endl;
	cin>>value;
	list->add(id,value); 
	cout<<"cost"<<endl;
	cin>>gn;
	cin.ignore();
	list->addgn(gn,1);
	
	cout<<"stat 2"<<endl;
	cin>>id;
	cout<<"Value 2"<<endl;
	cin>>value;
	list->add(id,value); 
	cout<<"cost"<<endl;
	cin>>gn;
	cin.ignore();
	list->addgn(gn,2);
	
	cout<<"stat 3"<<endl;
	cin>>id;
	cout<<"Value 3"<<endl;
	cin>>value;
	list->add(id,value); 
	cout<<"cost"<<endl;
	cin>>gn;
	cin.ignore();
	list->addgn(gn,3);
	list->calculat();
	
	return 0;
}
