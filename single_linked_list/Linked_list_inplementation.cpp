/*
Improvements:
1. In your deleteList function, it might be more user-friendly to inform users how many nodes were deleted rather than just printing "Program ended".

2."insertAtAnyPosition" and "updateValue" both the function should check if the position is valid or not.

Note: We should always store the part we want to delete from 
our linked list and after that we should free that memory. This just for 
better memory management.

1. Insert at the end/tail.
2. Insert at the head.
3. Insert at arbitary position.

4. Updating value at arbitary position.

5. Delete at Head.
6. Delete at an Arbitary position.

*/


#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    Node()
    {
        next = NULL;
    }
};

void insertAtTail(Node* &head, int data)    // Inserting at Tail
{
    Node* new_node = new Node(data);
    if(head == NULL)
    {
        head =  new_node;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;   
}

void insertAtHead(Node* &head, int value) // Inserting at Head
{
    Node* new_node =  new Node(value);

    new_node->next = head;
    head = new_node; 
}

void insertAtAnyPosition(Node* head, int position, int value) // Inserting at arbitary position.
{
    if(position == 0)
    {
        insertAtHead(head, value);
        return;
    }
    
    Node* new_node = new Node(value);
    Node* temp = head;
    int current_pos = 0;

    while(current_pos != position-1)
    {
        temp = temp->next;
        current_pos++; // tracking my current position.
    }
    // here my temp is pointing to node at (position - 1)

    new_node->next = temp->next;
    temp->next = new_node;
}

void updateValue(Node* &head, int position, int value)   //Update value at any position.
{
    Node* new_node = new Node(value);
    Node* temp = head;
    int current_pos = 0;
    
    while(current_pos != position)
    {
        temp = temp->next;
        current_pos++;
    }
    temp->data = value;
}

void deleteAtStart(Node* &head)                                 // deleting node at the Start.
{
    if(head == NULL) //this one is for better memory management.
    {
        cout<<"Linked_List is empty"<<endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    free (temp);
}

void deleteAtEnd(Node* &head)                                 // deleting node at the End.
{
    
    if(head == NULL) //this one is for better memory management.
    {
        cout<<"Linked_List is empty"<<endl;
        return;
    }
    // if(head->next == NULL) -- is for better memory handeling. when the list has only one node then
    // the code will show undefined behaviour as second_last->next->next does not exists.
    // to handle this situation we need this piece of code.
    if(head->next == NULL)
    {
        cout<<"Linked list is now empty."<<endl;
        delete head;
        head = NULL;
        return;
    }
    Node* second_last = head;
    while(second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }
    // now second_last points to second last node.
    Node* temp = second_last->next;
    second_last->next = NULL;
    free(temp);
}

void deleteAtAny(Node* &head, int position)                 // deleting node at arbitary position.
{
    if(position == 0)
    {
        deleteAtStart(head);
        return;
    }
    int curr_position = 0;
    Node* prev = head;

    while(curr_position !=  position-1)
    {
        prev = prev->next;
        curr_position++;
    }

    // now prev is pointing to node at position -1.
    Node* temp = prev->next; // node to be deleted.
    prev->next = prev->next->next;
    delete temp;
}

void display(Node* head)                                     // Displaying the Linked list
{   
    Node* temp = head;
    cout<<endl<<endl;
    cout<<"Our Linked list is : ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<" NULL"<<endl<<endl;
}

void deleteList(Node* &head)     // Creating a destructur for better memory management
{
    Node* temp;
    int count = 0;

    while(head!=NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    cout<<count<<" nodes deleted"<<endl<<"Program ended"<<endl;
}


int main()      // The main function.
{
Node* head = NULL;
int choice, data, position;

while(true)
{
    cout<<"# LINKED LIST PRACTICE : "<<endl; 
    cout<<"1. Insert at the End."<<endl;
    cout<<"2. to display."<<endl;
    cout<<"3. Insert at the Head ."<<endl; 
    cout<<"4. Insert at the Any Position ."<<endl; 
    cout<<"5. Update value at any position."<<endl;
    
    cout<<"6. Delete at Start. "<<endl;
    cout<<"7. Delete at End. "<<endl;
    cout<<"8. Delete at Arbitary Position."<<endl; 

    cout<<"any other. to exit."<<endl<<endl;

    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"Enter the value : ";
            cin>>data;
            insertAtTail(head, data);
            break;
        case 2:
            display(head);
            break;
        case 3:
            cout<<"Enter the value : ";
            cin>>data;
            insertAtHead(head, data);
            break;
        case 4:
            cout<<"Enter the position : ";
            cin>>position;
            cout<<endl;
            cout<<"Enter the value : ";
            cin>>data;
            insertAtAnyPosition(head, position, data);
            break;
        case 5: 
            cout<<"Enter the position : ";
            cin>>position;
            cout<<endl;
            cout<<"Enter the value : ";
            cin>>data;
            updateValue(head, position, data);
            break;
        case 6:
            deleteAtStart(head);
            cout<<"First Node has deleted."<<endl;
            break;
        case 7: 
            deleteAtEnd(head);
            cout<<"Last Node has deleted."<<endl;
            break;
        case 8:
            cout<<"Enter the position : ";
            cin>>position;
            cout<<endl;
            deleteAtAny(head, position);
            break;
        default:
            deleteList(head);
            return 0;   
    }
}

    return 0;
}
