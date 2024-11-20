/*
    Given head of a Linked_List, delete every alternate element from the list starting from the second element.

    Hint: two stopping conditions
    1. if even no of nodes: current = NULL;
    2. if odd no of nodes: current->next = NULL;
*/

#include <iostream>
using namespace std;

class Node              //creating a class for nodes.
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class linkedList        //creating a class for linked list.
{
    // here the property of the linkedList will be head.
    // As we could access the whole linkedList using the head.
public:
    Node* head;

    linkedList()
    {
        head = NULL;
    }

    ~linkedList()       // creating a destructor for better memory management.
    {
        Node* current_Node = head;
        Node* next_Node;

        while(current_Node != NULL)
        {
            next_Node = current_Node->next;
            delete current_Node;
            current_Node = next_Node;

        } 
    }

    void inserAtTail(int value)
    {   
        Node* new_node = new Node(value);
        if(head == NULL)
        {
            head = new_node;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        //now we are at the last node.
        temp->next = new_node;
    }

    void display(){  
    // we do not have to pass the parameter Node* head as we are inside the class.
    Node* temp = head;
    while(temp != NULL)
    {   
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<" NULL"<<endl;
    }


};

void deleteAlternateNodes(Node* head)
{
    Node* curr_node = head;
    while(curr_node != NULL && curr_node->next != NULL)
    {
        Node* temp = curr_node->next;  //this is the node to be deleted.
        curr_node->next = curr_node->next->next;
        delete temp;
        curr_node = curr_node->next; // updating our current node.
    }
}

int main()
{
linkedList ll;
int choice, data, position;

while(true)
{
    cout<<"# LINKED LIST PRACTICE : "<<endl; 
    cout<<"1. Insert at the End."<<endl;
    cout<<"2. to display."<<endl;
    cout<<"3. Delete alternate nodes."<<endl;
    
    cout<<"any other. to exit."<<endl<<endl;

    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"Enter the value : ";
            cin>>data;
            ll.inserAtTail(data);
            break;
        case 2:
            ll.display();
            break;
        case 3: 
            deleteAlternateNodes(ll.head);
            break;
        default:
            cout<<"Program Ended."<<endl;
            return 0;   
    }
}

    return 0;
}
