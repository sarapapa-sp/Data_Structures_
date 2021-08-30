/*
 * @author- sarapapa
 * Date - 
 * 
 * Implementation of double  Linked list using c++
 * This program is menu driven program
 * 
 * 
 * 
 * */
 
 #include <iostream>
 using namespace std;
 
 //defining the class with the pointer
 class Node{
	public:
		Node* q;   //pointer to point backwards
		int k;     //to store the value
		Node* p;   //pointer to point next
 };
 
 //Creating the public pointer to the class Node
 Node* head=NULL;  //to point at the head of list
 Node* tail=NULL;  //to point at the end of list
 int k=-1;         //to keep track of number of elements in list
 
 // Initilizing the functions to work with List
 void insertAtstart();       //add element at start
 void insertAtlast();        //add element at last
 void insertatposition();    //add element at a position
 void deleteAtfirst();       //remove the first element 
 void deleteAtlast();        //remove the last element
 void deleteatposition();    //remove the element at a position
 void display_list();        //display the list
 
 //main()
 int main(){
	cout<<"Circular Linked List";
    int flag=1,input;

    while (flag==1){
        cout<<"\n1 to insert node at first\n2 to insert node at last\n3 to insert node at location\n";
        cout<<"4 to delete at first\n5 to delete at last\n6 to delete at location";
        cout<<"\n7 to display\n8 to terminate\n\tSelect your choice : ";
        cin>>input;
        switch(input){
            case 1:
                insertAtstart();
                break;
            case 2:
                insertAtlast();
                break;
            case 3:
                insertatposition();
                break;
            case 4:
                deleteAtfirst();
                break;
            case 5:
                deleteAtlast();
                break;
            case 6:
                deleteatposition();
                break;
            case 7:
                display_list();
                break;
            case 8:
                flag=10;
                break;
            default:
                cout<<"Invalid entry !";
        }
    }
	return 0;
 }
 
 //implementing the functions
 void insertAtstart(){
	int value;
	cout<<"Enter the value :";
	cin>>value;
	Node* add=new Node();
	add->k=value;
	if(head==NULL){
		head=add;
		tail=head;
		head->p=NULL;
		head->q=NULL;
	}else{
		head->q=add;
		add->p=head;
		head=add;
		head->q=NULL;
	}
	k++;
	add=NULL;
 }
 
 void insertAtlast(){
	int value;
	cout<<"Enter the value :";
	cin>>value;
	Node* add=new Node();
	add->k=value;
	if(head==NULL){
		head=add;
		tail=head;
		head->p=NULL;
		head->q=NULL;
	}else{
		tail->p=add;
		add->q=tail;
		tail=add;
		tail->p=NULL;
	}
	k++;
	add=NULL;
 }
 
 void insertatposition(){
	int pos;
    cout<<"Enter the position :";
    cin>>pos;
    if(pos > k || pos < 0)
        cout<<"Position is wrong\n";
    else{
        int value;
        cout<<"Enter the value : ";
        cin>>value;
        Node* insert;
        insert=new Node();
        insert->k=value;
        
        //inserting the value
        Node* e;
        Node* f;
        e=head;
        f=e->p;
        for(int i=1;i<pos;i++){
            e=f;
            f=f->p;
        }
        e->p=insert;
		insert->q=e;
        insert->p=f;
		f->q=insert;
		k++;
		insert=NULL;
		e=NULL;
		f=NULL;
    }
	cout<<"\n";
 }
 
 void deleteAtfirst(){
	if(head==NULL){
		cout<<"Nothing to remove!!";
	}else if(head==tail){
		cout<<"Element removed :"<<head->k;
		head=NULL;
		tail=NULL;
		k--;
	}else{
		cout<<"Element removed :"<<head->k;
		head=head->p;
		head->q=NULL;
		k--;
	}
	cout<<"\n";
 }
 
 void deleteAtlast(){
	if(head==NULL){
		cout<<"Nothing to remove!!";
	}else if(head==tail){
		cout<<"Element removed :"<<tail->k;
		head=NULL;
		tail=NULL;
		k--;
	}else{
		cout<<"Element removed :"<<tail->k;
		tail=tail->q;
		tail->p=NULL;
		k--;
	}
	cout<<"\n";
 }
 
 void deleteatposition(){
	if(head==NULL)
        cout<<"Nothing to remove!"<<"\n";
    else if(head==tail){
        cout<<"Element removed"<<head->k<<"\n";
        head=NULL;
        tail=NULL;
    }else{
        int pos;
        cout<<"Enter the position :";
        cin>>pos;
        if(pos<0 || pos>k){
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
			f->q=e;
            e=NULL;
            f=NULL;
	        k--;
        }
    }
 }
 
 void display_list(){
	if(head==NULL){
		cout<<"Nothing to show !!";
	}else if(head==tail){
		cout<<"List is :\n"<<head->k;
	}else{
		cout<<"List is :\n";
		Node* disp;
		disp=head;
		while(disp!=tail){
			cout<<disp->k<<" ";
			disp=disp->p;
		}
		cout<<disp->k;
		disp=NULL;
	}
	cout<<"\n";
 }
 
 