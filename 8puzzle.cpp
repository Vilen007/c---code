#include <iostream>
#include <string>
#include<fstream>
using namespace std;

int main()
{   
    ifstream infile("InitAndGoal.txt");
    
    int position[10];
    int m;
    int count=1;
    string filepos;

    
	if(infile.is_open())
	{ 
      for(int i=0; i < 9; i++)
      {
           infile >> position[i]; 
      } 
    }
    
    int pos = 0;
    
    while(infile >> m >> filepos)
    {
     for(int i=1; i<10; i++)
     {   
        
        if(position[i]==0)
          pos = i;
            
        if(filepos=="left" && (i-1)==pos && position[i]==m) 
        {
          int tem = 0;
          tem = position[i-1];
          position[i-1] = position[i];
          position[i] = tem;
          count+1;       
        }
        else if(filepos=="right" && (i+1)==pos  && position[i]==m)  
        {
          int tem =0;
          tem = position[i+1];
          position[i+1] = position[i];
          position[i] = tem;
          count+1;       
        }
        else if(filepos=="up" && (i-3)==pos  && position[i]==m) 
        {
          int tem =0;
          tem = position[i-3];
          position[i-3] = position[i];
          position[i] = tem;
          count+1;       
        }
        else if(filepos=="down" && (i+3)==pos  && position[i]==m) 
        {
          int tem =0;
          tem = position[i+3];
          position[i+3] = position[i];
          position[i] = tem;
          count+1;       
        }  
     }
      
    }
      
      for(int i=2; i <= 9; i++)
     {
     	if(i == 2){
     		cout<<1<<" ";
     		cout<<0<<" ";
     		continue;
		 }
		 else{
         cout << i-1 << " ";
         if(i == 3 || i == 6){
         	 cout<<endl;
		 }
     }
    
     }  
    if(count==0)
    {
         cout << "Invalid Move" << endl;
    }    
    
      
    return 0;
}
