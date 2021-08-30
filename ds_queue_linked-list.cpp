/*
 * @author- sarapapa
 * Date - 
 * 
 * Implementation of Queue using a Linked list using c++
 * This program is menu driven program
 * 
 * Queue is based on FIFO (First in , first out)
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
 
 // Initilizing the operations/methods
 void add();        //To add the element to the queue
 void remove();     //To remove the element from the queue
 void display();    //To display the queue
 
 //main()
 int main(){
	 cout<<"Queue using linked list";
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

//implementing the method
void add(){
	//Taking value in a node "temp"
	Node* temp;
	temp=new Node();
	int value;
	cout<<"Enter the value :";
	cin>>value;
	temp->k=value;
	temp->p=NULL;
	if(head==NULL){
		head=temp;
		tail=head;
	}else{
		tail->p=temp;
		tail=temp;
		tail->p=NULL;
	}
	temp=NULL;  //releasing the pointer
}
void remove(){
	if(head==NULL)
		cout<<"Nothing to remove .\n";
	else{
		cout<<"Element dropped is :"<<head->k<<" \n";
		Node* rem;
		rem=head->p;
		head=NULL;
		head=rem;
		rem=NULL;
	}	
}
void display(){
	if(head==NULL){
		cout<<"The Queue is empty !!\n";
	}else{
		Node* disp;
		disp=head;
		cout<<"Queue is :\n\t";
		while(disp!=NULL){
			cout<<disp->k<<" ";
			disp=disp->p;
		}
		cout<<"\n";
	}
}
 
 
 
 
 
 
 