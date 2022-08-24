#include <iostream>
using namespace std;
int main(){
	int puzzleboard[3][3] = {{2,8,3},{1,6,4},{0,7,5}};
	int goalstate[3][3]= {{1,2,3},{8,0,4},{7,6,5}};
		
//	int puzzleboard[3][3];
//	int goalstate[3][3];
//	cout<<"Input your puzzle Initial State:"<<endl;
//	for(int i = 0; i<3; i++){
//		for(int j = 0; j < 3; j++){
//			cout<<"Row "<<i+1<<" Value "<<j + 1<<endl;
//			cin>>puzzleboard[i][j];	
//		}
//	} 
//	cin.ignore();
//	cout<<"Input your puzzle Goal State:"<<endl;
//	for(int i = 0; i<3; i++){
//		for(int j = 0; j < 3; j++){
//			cout<<"Row "<<i+1<<" Value "<<j + 1<<endl;
//			cin>>goalstate[i][j];	
//		}
//	} 
//	cin.ignore();
	
	int index_i,index_j;
	for(int i = 0; i<3; i++){
		for(int j = 0; j < 3; j++){
			cout<<puzzleboard[i][j]<<" "; 	
	}
	cout<<endl;
	} 
	int yes = 1;
	while(yes){
		input:
		string choice;
		cout<<"Enter Your choice, it must be in up, left down, right or H2 for heuristic 2 or end to stop \n";
		getline(cin,choice);
	
		for(int i = 0; i< 3; i++){
			for(int j = 0; j < 3; j++){
				if(puzzleboard[i][j] == 0){
					index_i = i;
					index_j = j;
					}
				}	
			}
		if(choice == "right"){
						if(puzzleboard[0][2] == 0 || puzzleboard[1][2] == 0 || puzzleboard[2][2] == 0){
							cout<<"invalid move"<<endl;
							goto input;
						}
						else{
							int swap = 0;
							swap = puzzleboard[index_i][index_j];
							puzzleboard[index_i][index_j] = puzzleboard[index_i][index_j + 1];
							puzzleboard[index_i][index_j + 1] = swap;
								
						}
						
					}
					else if(choice == "left"){
						if(puzzleboard[0][0] == 0 || puzzleboard[1][0] == 0 || puzzleboard[2][0] == 0){
							cout<<"invalid move"<<endl;
							goto input;
						}
						else{
							int swap = 0;
							swap = puzzleboard[index_i][index_j];
							puzzleboard[index_i][index_j] = puzzleboard[index_i][index_j - 1];
							puzzleboard[index_i][index_j - 1] = swap;
						}
					}
					else if(choice == "down"){
						if(puzzleboard[2][0] == 0 || puzzleboard[2][1] == 0 || puzzleboard[2][2] == 0){
							cout<<"invalid move"<<endl;
							goto input;
						}
						else{
							int swap = 0;
							swap = puzzleboard[index_i][index_j];
							puzzleboard[index_i][index_j] = puzzleboard[index_i+1][index_j];
							puzzleboard[index_i+1][index_j] = swap;
						}	
					}
					else if(choice == "up"){
						if(puzzleboard[0][0] == 0 || puzzleboard[0][1] == 0 || puzzleboard[0][2] == 0){
							cout<<"invalid move"<<endl;
							goto input;
						}
						else{
							int swap = 0;
							swap = puzzleboard[index_i][index_j];
							puzzleboard[index_i][index_j] = puzzleboard[index_i -1][index_j];
							puzzleboard[index_i-1][index_j] = swap;
						}
					}
					else if(choice == "end") {
						int match = 0;
						for(int i = 0; i < 3; i++){
							for(int j=0; j < 3; j++){
								if(puzzleboard[i][j] == goalstate[i][j]){
									match++;
								}
							}
						}
						if(match == 9){
								cout<<"Congratulations !! YOu reached your goal state: \n";
							yes = 0;
						}
						else{
							cout<<"Unfortunately ! You didn't achieve Goal State \n";
							yes = 0;
						}
					}
					
					else if(choice == "h2"){
						int match = 0;
						for(int i = 0; i < 3; i++){
							for(int j=0; j < 3; j++){
								if(puzzleboard[i][j] != goalstate[i][j]){
									match++;
								}
							}
						}
						cout<<"Heuristic 2:"<<match<<endl;
					}	
					else{
						cout<<"Invalid Input \n";
						goto input;
					}
					for(int i1 = 0; i1<3; i1++){
									for(int j1 = 0; j1 < 3; j1++){
										cout<<puzzleboard[i1][j1]<<" "; 	
								}
								cout<<endl;
								}
		}


	return 0;
}
