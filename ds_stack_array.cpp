/*
 * @author sarapapa
 * Date - 
 * 
 * Implementation of Stack using the array in c++
 * This program is menu driven program
 * 
 * Stack is based on LIFO (Last in , first out)
 * 
 * */
 
 #include <iostream>
 using namespace std;
 
 
 // defining the global array and its size
 const int n=10; //keep the fixed size , its size of the array
 int stack[n];   //array to store the elements of the stack
 int k;          //to keep track of total elements  in the stack

 //defining/initilizing  the functions to do operation on the global array
 void push();           // To push element at last
 void pop();        // To pop the element from last 
 void display();       // To display the Stack

 //main method
 int main(){
	 cout<<"Stack using array\n";
	int flag=0,input;
	while(flag==0){
		cout<<"\n1 to push \n2 to pop \n3 to display the Stack\n4 to terminate\n\t Enter your choice :";
		cin>>input;
		switch(input){
			case 1: push();
				break;
			case 2: pop();
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
 //implementing methods
 void push(){
	 if(k<n){
		 int value;
		 cout<<"Enter the value :";
		 cin>>value;
		 stack[k]=value;
		 k++;
	 }else{
		 cout<<"Stack is full!\n";
	 }
 }
 void pop(){
	 if(k==0)
		 cout<<"Stack is empty!!\n";
	 else{
		 cout<<"Element poped is "<<stack[k-1]<<"\n";
		 k--;
	 }	 
	 
 }
 void display(){
	 if(k==0)
		 cout<<"Nothing to show!\n";
	 else{
		 cout<<"Stack is :\n\t";
		 for(int i=0;i<k;i++)
			 cout<<stack[i]<<" ";
		 cout<<"\n";
	 }
	 
 }