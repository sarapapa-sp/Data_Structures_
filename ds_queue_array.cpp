/*
 * @author sarapapa
 * Date - 
 * 
 * Implementation of Queue using the array in c++
 * This program is menu driven program
 * 
 * Queue is based on FIFO (First in , first out)
 * 
 * */



#include <iostream>
using namespace std;

// defining the global array and its size
const int n=10; //keep the fixed size , its size of the array
int queue[n];   //array to store the elements of the queue
int k;          //to keep track of total elements  in the queue

//defining/initilizing  the functions to do operation on the global array
void add();           // To add the element at last
void remove();        // To remove the element from first 
void display();       // To display the Queue

int main(){
	int flag=0,input;
	while(flag==0){
		cout<<"\n1 to add \n2 to remove \n3 to display the queue\n4 to terminate\n\t Enter your choice :";
		cin>>input;
		switch(input){
			case 1: add();
				break;
			case 2: remove();
				break;
			case 3: display();
				break;
			case 4:
				cout<<"\n Process terminated \n";
				flag=1;
				break;
			default:
				cout<<"Invalid Entry";
		}
	}
	return 0;
}
//implementing the methods
void add(){
	//reading the value
	int value;
	cout<<"Enter the element : ";
	cin>>value;
	//inserting the value
	if(k<=n){
		queue[k]=value;
		k++;
	}else{
		cout<<"The Queue is full!!\n";
	}
}
void remove(){
	if(k==0)
		cout<<"Nothing to remove.\n";
	else{
		cout<<"Element removed is "<<queue[0]<<"\n";
		for(int i=0;i<k-1;i++)
			queue[i]=queue[i+1];
		k--;
	}
}
void display(){
	if(k==0)
		cout<<"Queue is empty\n";
	else{
		cout<<"Queue is : \n\t";
		for (int i=0;i<k;i++)
			cout<<queue[i]<<" ";
		cout<<"\n";	
	}	
}