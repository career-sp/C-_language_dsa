/*
1. Iterative approach.
2. Recursive approach.
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

Node* reverseLL_recursion(Node* &head)               //reverse linked_list using recursion.
{
    // base case.
    if(head == NULL || head->next == NULL) 
    // if list have only element or no element.
    {
        return head;
    }

    // recursive case.
    Node* new_head = reverseLL_recursion(head->next);
    head->next->next = head;
    head->next = NULL; // as head is now pointing to last node in the reversed ll.
    return new_head;
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
    cout<<"3. Reorder Nodes into reverse order. (using Recursion)"<<endl;
    
    
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
            ll.head = reverseLL_recursion(ll.head);
            break;
        default:
            cout<<"Program Ended."<<endl;
            return 0;   
    }
}

return 0;
}
