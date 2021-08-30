/*
 * @author sarapapa
 * Date - 
 * 
 * Implementation of Circular Linked list
 * This program is menu driven program
 * 
 * The class Node will have 2 pointers
 * One pointing next and open pointing previous one
 * */
 
 #include <iostream>
 using namespace std;
 
 //
 class Node{
 public:
	int k; //stores the value
	Node* p; //points to the next node in the list
	Node* q; //points to the previous node in the list
 };

 //Creating the public pointer to the class Node
 Node* head=NULL;    //To point at the head of the list
 Node* tail=NULL;    //To point at the end of the list
 int total=-1;           // To keep track of elements in list

//initilizing the methods for operations
 void addAtfirst();         //add the node at first
 void addAtlast();          //add the node at last
 void addAtposition();      //add the node at the specific position
 void removeAtfirst();      //remove the node from the first position
 void removeAtlast();       //remove the node from the last position
 void removeAtposition();   //remove the node from the specific position
 void display();            //display the circular linked list

 //main method
 int main(){
	int flag=1,input;
	while(flag==1){
		cout<<"\n1 to add element at first\n2 to add at last\n3 to add at position\n4 to remove at first\n5 to remove at last\n6 to remove at position";
		cout<<"\n7 to display the list\n8 to terminate \n\tEnter the Choice :";
		cin>>input;
		switch(input){
			case 1:addAtfirst();
				break;
			case 2:addAtlast(); 
				break;
			case 3:addAtposition(); 
				break;
			case 4:removeAtfirst();
				break;
			case 5:removeAtlast(); 
				break;	
			case 6:removeAtposition();
				break;
			case 7:display();
				break;
			case 8:flag=0;
				break;
			default:
				cout<<"Invalid entry!!\n";	
		}
	}
	
 }
 void addAtfirst(){
	int value;
	cout<<"Enter the value :";
	cin>>value;
	Node* insert=new Node();
	insert->k=value;
	insert->q=NULL;
	insert->p=NULL;
	if(head==NULL){
		head=insert;
		tail=head;
	}else{
		insert->p=head;
		head->q=insert;
		head=insert;
	}
	total++;
	insert=NULL;
 }
 void addAtlast(){
	int value;
	cout<<"Enter the value :";
	cin>>value;
	Node* insert=new Node();
	insert->k=value;
	insert->q=NULL;
	insert->p=NULL;
	
	if(head==NULL){
		head=insert;
		tail=head;
	}else{
		tail->p=insert;
		insert->q=tail;
		tail=insert;
	}
	total++;
	insert=NULL;
 }
 void addAtposition(){
	int pos;
    cout<<"Enter the position :";
    cin>>pos;
    if(pos>(total+1))
        cout<<"Position is wrong\n";
    else{
        int value;
        cout<<"Enter the value : ";
        cin>>value;
        Node* insert;
        insert=new Node();
        insert->k=value;
        insert->p=NULL;
        //inserting the value
        Node*e;
        Node* f;
        e=head;
        f=e->p;
        for(int i=1;i<pos;i++){
            e=f;
            f=f->p;
        }
        e->p=insert;
        insert->p=f;
		total++;
    }
 }
 void removeAtfirst(){
	if(head==NULL)
		cout<<"Nothing to remove";
	else if(head==tail){
		cout<<"Element removed :"<<head->k;
		head=NULL;
		tail=NULL;
		total--;
	}else{
		cout<<"Element removed :"<<head->k;
		
		Node* rem;
		rem=head->p;
		rem->q=NULL;
		head=NULL;
		head=rem;
		rem=NULL;
		total--;
	}
	cout<<"\n";
 }
 void removeAtlast(){
	if(head==NULL)
		cout<<"Nothing to remove";
	else if(head==tail){
		cout<<"Element removed :"<<head->k;
		head=NULL;
		tail=NULL;
		total--;
	}else{
		cout<<"Element removed :"<<tail->k;
		Node* rem;
		rem=tail->q;
		rem->p=NULL;
		tail=NULL;
		tail=rem;
		rem=NULL;
		total--;
	}
	cout<<"\n";
 }
 void removeAtposition(){
	if(head==NULL)
        cout<<"Nothing to remove!"<<"\n";
    else if(head==tail){
        cout<<"Element removed"<<head->k<<"\n";
        head=NULL;
        tail=NULL;
		total--;
    }else{
        int pos;
        cout<<"Enter the position :";
        cin>>pos;
        if(pos<0 || pos>total){
            cout<<"Position invalid!!\n";
        }else{
            //deleting the value node
            Node*e;
            Node* f;
            e=head;
            f=e->p;
            for(int i=1;i<pos;i++){
                e=f;
                f=f->p;
            }
            cout<<"Element removes is :"<<f->k<<"\n";
            f=f->p;
            e->p=f;
            e=NULL;
            f=NULL;
			total--;
        }
    }
 }
 void display(){
	if(head==NULL)
		cout<<"Nothing to show !!\n";
	else{
		Node* disp=head;
		while(disp!=tail){
			cout<<disp->k<<" ";
			disp=disp->p;
		}
		cout<<disp->k;
		cout<<"\n";
	}	
 }

