/*
Circular linked list Implementation:

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
    }
};

class circular_list
{
public: 
    Node* head; //data member.
    circular_list()
    {
        head = NULL;
    }

    void insertAtStart(int data)
    {
        Node* new_node = new Node(data);
        if(head == NULL)
        {
            head = new_node;
            new_node -> next = head; // circular linked list.

        }

        Node* tail = head;
        while(tail->next !=head) // we can determine our last node.
        {
            tail = tail->next;
        }
        // tail node is pointing to the last node.

        tail->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    void display()
    {
        Node* temp = head;
        do
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        } while (temp != head);
        cout<<endl;
    }

    void printCircular()        // checking if it is circular or not visually.
    {
        Node* temp = head;
        for(int i=0; i<15; i++)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void insertAtEnd(int data)      // Inserting at the end of the list.
    {
        Node* new_node = new Node(data);

        if(head == NULL)
        {
            head = new_node;
            new_node->next = head; //circular linked list;
            return;
        }
        Node* tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }
        // here tail will be pointing to last node.
        tail->next = new_node;
        new_node->next = head;
    }
};

int main()
{
    circular_list cll;
    cll.insertAtStart(3);
    cll.insertAtStart(4);
    cll.insertAtStart(5);
    cll.insertAtStart(6);
    cll.display();

    cll.printCircular();

    

    return 0;
}

