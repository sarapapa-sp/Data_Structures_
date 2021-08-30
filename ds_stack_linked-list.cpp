/*
 * @author- sarapapa
 * Date - 
 * 
 * Implementation of Stack using a Linked list using c++
 * This program is menu driven program
 * 
 * Stack is based on LIFO (Last in , first out)
 * 
 * */
 
 #include <iostream>
 using namespace std;
 
 //defining the class with the pointer
 class Node{
	public:
		int k;
		Node* p;
 };
 
 
 //Creating the public pointer to the class Node
 
 Node* head=NULL;  // To point at the head of the queue
 Node* tail=NULL;  // To point at the end of the queue
 
 //initilizing the methods for the operation
 void push();
 void pop();
 void display();
 
 //int main
 int main(){
	cout<<"Implementation of Stack using Linked List\n";
	int flag=0,input;
	while(flag==0){
		cout<<"\n1 to push \n2 to pop \n3 to display the Stack\n4 to terminate\n\t Enter your choice :";
		cin>>input;
		switch(input){
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:flag=1;
			break;
			default:cout<<"Invalid entry!!";
		}
	}	
	return 0;
 }
 
 //implementing methods
 void push(){
	 int value;
	 cout<<"Enter the element :";
	 cin>>value;
	 Node* temp;
	 temp=new Node();
	 temp->k=value;
	 temp->p=NULL;
	 if(head==NULL){
		 head=temp;
		 tail=head;
		 
	 }else{
		 tail->p=temp;
		 tail=temp;
	 }
	 temp=NULL;
 }
 void pop(){
	 if(head==NULL)
		 cout<<"Stack is empty\n";
	 else if(head==tail){
		 cout<<"Element poped is :"<<head->k;
		 head=NULL;
		 tail=NULL;
	 }else{
		 cout<<"Element poped is :"<<tail->k;
		 Node* e;
		 Node* f;
		 e=head;
		 f=e->p;
		 while(f!=tail){
			 e=f;
			 f=f->p;
		 }
		 tail=NULL;
		 tail=e;
		 tail->p=NULL;
		 e=NULL;
		 f=NULL;
	 } 	 
 }
 void display(){
	 if(head==NULL){
		 cout<<"Stack is empty !";
	 }else{
		 cout<<"Stack is : \n\t";
		 Node* disp;
		 disp=head;
		 while(disp!=tail){
			 cout<<disp->k<<" ";
			 disp=disp->p;
		 }
		 cout<<disp->k<<"\n";
		 disp=NULL;
	 }
 }