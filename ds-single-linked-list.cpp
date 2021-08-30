/*
 * @author- sarapapa
 * Date - 
 * 
 * Implementation of single  Linked list using c++
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
    int  k;
    Node* p;
};

//Creating the public pointer to the class Node
Node* head=NULL;   // To point at the head of the queue
Node* tail=NULL;   // To point at the end of the queue
int k=-1;          // To keep track of elements in list
int value;         // To read the value 

// Initilizing the functions to work with List
void insertAtstart();
void insertAtlast();
void insertatposition();
void deleteAtfirst();
void deleteAtlast();
void deleteatposition();
void display_list();

int main(){
	cout<<"Hello!!!";
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
}


void insertAtstart(){
    Node* first;
    first=new Node();
    cout<<"Insert the k value:";
    cin>>value;
    first->k=value;
    first->p=NULL;
    if(head==NULL){
        head=first;
        tail=head;
    }else{
        first->p=head;
        head=first;

    }
    first=NULL;
    k++;
}
void insertAtlast(){
    int value;
    cout<<"Enter the value  :";
    cin>>value;
    Node* insert;
    insert=new Node();
    insert->k=value;
    insert->p=NULL;
    //inserting it
    if(head==NULL){
        head=insert;
        tail=head;
        tail->p=NULL;
    } else{
        tail->p=insert;
        tail=insert;
        tail->p=NULL;
    }
    insert=NULL;
    k++;
}
void insertatposition(){
    int pos;
    cout<<"Enter the position :";
    cin>>pos;
    if(pos>(k+1))
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
		k++;
    }
}
void deleteAtfirst(){
    //delete at first
    if(head==NULL)
        cout<<"List is empty";
    else if(head->p==NULL){

        cout<<"Element removed "<<head->k;
        head=NULL;
        k--;
    } else{
		cout<<"Element removed :"<<head->k;
        Node* x;
        x=head->p;
        head=NULL;
        head=x;
        x=NULL;
        k--;
    }
	cout<<"\n";

}
void deleteAtlast(){
    if(head==NULL)
        cout<<"List is empty";
    else{
		cout<<"Element removed :"<<tail->k;
        Node* e;
        Node* f;
        e=head;
        f=e->p;
        while(f!=tail){
            e=f;
            f=f->p;
        }
        tail=e;
        tail->p=NULL;
        e=NULL;
        f=NULL;
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
            e=NULL;
            f=NULL;
	    k--;
        }
    }

}
void display_list(){
    Node* e=head;
    while (e!=NULL){
        cout<<e->k<<" ";
        e=e->p;
    }
    cout<<"\n";
}
