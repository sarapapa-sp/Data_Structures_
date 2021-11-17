/*
 * @author- sarapapa
 * Date -
 *
 * Sorting 2
 * Quick sort
 * Sorting an linked list using Quick sort
 *
 *
 * */

#include <iostream>

using namespace std;

class node{
public:
    int k;
    node* next;
};


void insertAtbeginning(node**head,int data); // to insert the node at first
void display(node**head);                    // to print the linked list
node *getTail(node *temp);                   // to get the last node of the list
node *partition(node *head ,node *end,node **newHead,node **newEnd); //Partition of the list using last element as pivot element
void quicksort(node **head);                 // function to make the quick sort implement
node *quicksortrec(node *head,node *end);   //sorting happens exclusive of the end node

int main(){
    node *head = NULL;
    node *tail = NULL;

    int input;
    int data;
    int flag= 1;
    while (flag){
        cout<<"\n1 to add node \n2 to perform quick sort and end\n\t Your choice :";
        cin>>input;
        switch (input) {
            case 1:
                cout<<"Enter the data :";
                cin>>data;
                insertAtbeginning(&head , data);
                break;
            case 2:
                cout<<"Linked list before sorting will be : \n";
                display(&head);

                //calling the quick sort function
                quicksort(&head);
                cout<<"\nSorted list is :\n";
                display(&head);
                break;
            case 3:
                flag=0;
                break;
            default:
                cout<<"\ninvalid\n";
        }
    }


    return 0;
}

// to insert the node at first
void insertAtbeginning(node**head,int data) {
    node *temp = new node;

    //Making the new node
    temp->k = data;
    temp->next = NULL;

    if(*head == NULL)
        *head=temp;
    else{
        /*
         * adding the temp node on head node
         * making the next pointer of current node
         * point to present head
         * */
        temp ->next = *head;
        *head = temp;
    }

}
//to print the linked list
void display(node**head){
    node* temp = *head;
    while(temp!=NULL){
        cout<<temp->k<<" ";
        temp = temp->next;
    }
}
// to get the last node of the list
node *getTail(node *temp){
    while(temp !=NULL && temp->next != NULL)
        temp = temp->next;

    return temp;
}
//Partition of the list using last element as pivot element
node *partition(node *head ,node *end,node **newHead,node **newEnd){
    node *pivot = end; //taking pivot as the last node
    node *prev = NULL;
    node *temp = head;
    node *tail = pivot;

    while (temp != pivot){

        if(temp->k < pivot->k){
            if((*newHead) == NULL)
                (*newHead) = temp;
            prev = temp;
            temp = temp ->next;
        }else{
            /*if our temp node is greater than pivot
             * move our temp to tail and change the tail
             * */

            if(prev)
                prev->next = temp->next;

            node *t = temp->next;
            temp->next = NULL;
            tail->next=temp;
            tail = temp;
            temp = t;
        }
    }

    /*
     * if pivot is the smallest in list it becomes the new head
     * */
    if((*newHead) == NULL)
        (*newHead) = pivot;
    // new tail
    (*newEnd) = tail;

    return pivot;
}
// function to make the quick sort implement
void quicksort(node **head){
    (*head) = quicksortrec(*head, getTail(*head));
}
//sorting happens exclusive of the end node
node *quicksortrec(node *head,node *end){
    // base condition
    if(head == end || !head)
        return head;

    node *newhead= NULL , *newTail = NULL;

    node *pivot = partition(head , end , &newhead , &newTail);

    if(newhead != pivot){
        // set the node before pivot as NULL
        node *temp = newhead;
        while(temp->next != pivot)
            temp = temp->next;

        temp->next = NULL;

        // using recursion for the list before the pivot
        newhead = quicksortrec(newhead , temp);

        temp = getTail(newhead);
        temp->next = pivot;
    }
    pivot->next = quicksortrec(pivot->next , newTail);

    return newhead;
}
