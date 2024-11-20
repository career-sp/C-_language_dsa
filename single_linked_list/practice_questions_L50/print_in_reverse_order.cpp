/*Question:
Given the head of a singly linked list and we have to print the reverse list.

note: actually our linked list will be same we have to just print in the reverse order.
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
};

class linked_list
{
public:
    Node* head;

    linked_list()
    {
    head = NULL;
    }

    ~linked_list()  // creating a destructor.
    {
        Node* current_node = head;
        Node* next_node;

        while(current_node != NULL)
        {
            next_node = current_node->next;
            delete current_node;
            current_node = next_node;
        }


    }
    void insertAtTail(int value)
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
        temp->next = new_node;
    }

    void display()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<" NULL "<<endl;
    }

};

void reversePrint(Node* head)       // Printing Nodes into reverse order using Recursion.
{
    if(head == NULL) //base case
    {
        return;
    }
    reversePrint(head->next);   // recursive logic.
    cout<<head->data<<" -> ";
}




int main()
{
linked_list ll;
int choice, data, position;

while(true)
{
    cout<<"# LINKED LIST PRACTICE : "<<endl; 
    cout<<"1. Insert at the End."<<endl;
    cout<<"2. to display."<<endl;
    cout<<"3. Printing Nodes into reverse order."<<endl;
    
    cout<<"any other. to exit."<<endl<<endl;

    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"Enter the value : ";
            cin>>data;
            ll.insertAtTail(data);
            break;
        case 2:
            ll.display();
            break;
        case 3: 
            reversePrint(ll.head);
            break;
        default:
            cout<<"Program Ended."<<endl;
            return 0;   
    }
}

return 0;
}
