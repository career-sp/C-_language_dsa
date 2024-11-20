/*
Every node in doubly linked list will point to it's next node as well as it's previous node.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtStart(int data)                // Insert at the Head.
    {
        Node* new_node = new Node(data);
        // firstly if the linked list is empty or not.
        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    
    void insertAtEnd(int data)                // Insert at the End.
    {
        Node* new_node = new Node(data);
        // firstly if the linked list is empty or not.
        if(tail == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

    void insertAtPosition_chatgpt(int data, int k)      // Insert at any position.
    {
        if(k<=1) //Insert At Start
        {
            insertAtStart(data);
            return;
        }
        // assuming k is less or equal to length of doubly linked list.
        // first we have to traverse upto k-1 position.

        Node* temp = head;
        int count = 1; // 1 based indexing.
        while(temp != NULL && count < k-1)
        {
            temp = temp->next;
            count++;
        }
        // here temp will be pointing to the node at (k-1) position.

        if(temp == NULL) // If k is greater than the length of the list.
        {
            insertAtEnd(data);
            return;
        }

        Node* new_node = new Node(data);

        // steps for inserting at arbitary position.
        new_node->next = temp->next;

        if(temp->next != NULL)
        {
            temp->next->prev = new_node; // Link back to new node.
        }
        else
        {
            tail = new_node; // update tail if we are inserting at the end.
        }
        temp->next = new_node;
        new_node->prev = temp;
    }

    void deleteAtStart()                 // Deleting node from the Start.
    {
        if(head == NULL)
        {
            return;
        }

        Node* temp = head;
        head = head->next;

        if(head == NULL)    // lists having only one node.
        {
            tail = NULL;
        }
        else // handeling if the list only one element.
        {
            head->prev = NULL;
        }
        delete temp;

    }

    void deleteAtEnd()
    {
        if(head == NULL)
        {
            return;
        }
        Node* temp = tail;
        //tail->prev->next = NULL;
        tail = tail->prev;
        if(tail == NULL){
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        delete temp;
        return;
    }

    void deleteAtPosition(int k)        // Delete from any position
    {
        // Assuming k is less than or equal to the lists.
        Node* temp = head;
        int counter = 1;
        while(counter<k)
        {
            temp = temp->next;
            counter++;
        }
        // now temp is pointing to node at k th position.
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }


    void display()                      //Display the list.
    {
        Node* temp = head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<" NULL "<<endl;
    }  
};

int main()      // The main function.
{
DoublyLinkedList dll;
int choice, data, position;

while(true)
{
    cout<<"# Doubly LINKED LIST PRACTICE : "<<endl; 
    cout<<"1. Insert at the End."<<endl;
    cout<<"2. to display."<<endl;
    cout<<"3. Insert at the Head ."<<endl; 
    cout<<"4. Insert at the Any Position ."<<endl; 
    
    cout<<"5. Delete at Start. "<<endl;
    cout<<"6. Delete at End. "<<endl;
    cout<<"7. Delete at Arbitary Position."<<endl; 

    cout<<"any other. to exit."<<endl<<endl;

    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"Enter the value : ";
            cin>>data;
            dll.insertAtEnd(data);
            break;
        case 2:
            dll.display();
            break;
        case 3:
            cout<<"Enter the value : ";
            cin>>data;
            dll.insertAtStart(data);
            break;
        case 4:
            cout<<"Enter the position : ";
            cin>>position;
            cout<<endl;
            cout<<"Enter the value : ";
            cin>>data;
            dll.insertAtPosition_chatgpt(position, data);
            break;
        case 5:
            dll.deleteAtStart();
            cout<<"First Node has deleted."<<endl;
            break;
        case 6: 
            dll.deleteAtEnd();
            cout<<"Last Node has deleted."<<endl;
            break;
        case 7:
            cout<<"Enter the position : ";
            cin>>position;
            cout<<endl;
            dll.deleteAtPosition(position);
            break;
        default:
            return 0;   
    }
}

    return 0;
}
