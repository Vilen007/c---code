#include<iostream>
#include <String>
using namespace std;
class Node{
	public:
	Node(int data, string name){
		heuristicValue = data;
		nodeName = name;
		next = NULL;
	}
	string nodeName;
	int heuristicValue;
	Node * next;

};

class AStar
{
	// this is the cost between two nodes
	int cost[20];
	
	//for storing hueristics function results
	double hueristiResult[20];
private:
	Node * head;
	Node * tail;

public:
	AStar(){
		head = NULL;
		tail = NULL;
	}
	bool isEmpty(){
		return head == NULL;
	}
	void add(string name,int value){
		if (isEmpty())
		{
			head = new Node(value,name);
			tail = head;
		}else{
			tail->next = new Node(value,name);
			tail = tail->next;
		}
	}
	
	void addCost(int Nodecost, int index){
		cost[index]	= Nodecost;
	}
	
	void display(){
		Node * itor = head;
		while(itor != NULL){
			cout << itor->nodeName<< "-->";
			itor = itor->next;
		}
		
		
	}
	
	
	void hueristic_Function(string init,string goal){
		// here we can use hueristic function formula 
		// h(n) = f(n) + g(n)
		Node * initNode = head;
		int count = 0;
		int p = 0;
		while(initNode != NULL){
			hueristiResult[count] = initNode->heuristicValue + cost[p];
			initNode = initNode->next;
			count++;
			p++;
		}
	}
	
	void shortpath(){
		int min;
		for(int i = 0; i <= 5; i++){
			if(hueristiResult[i] < hueristiResult[i+1] ){
				min = cost[1];
			}
		}
		cout<<"So SHortest path is:"<<min;
	}
	
};
int main()
{
	AStar * list = new AStar();
	int nodeno;
	string nam;
	int hval = 0;
	int cost;
	cout<<"How many Nodes You Want in Your Graph"<<endl;
	cin>>nodeno;
	cin.ignore();
	for(int i = 0; i<nodeno; i++){
		
		cout<<"Enter Node name"<<endl;
		getline(cin,nam);
		cout<<"Enter Hueristic Valu"<<endl;
		cin>>hval;
		list->add(nam,hval); 
		cout<<"Enter Cost between two:"<<endl;
		cin>>cost;
		cin.ignore();
		list->addCost(cost,i);
	}
	string init,goal;
	cout<<"Initial Node Name"<<endl;
	cin>>init;
	cin.ignore();
	cout<<"Goal Node Name"<<endl;
	cin>>goal;

	
	list->hueristic_Function(init,goal);
	
	list->display();
	list->shortpath();
	return 0;
}
