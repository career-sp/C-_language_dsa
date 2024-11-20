/*
Question:
    Given the head of a doubly linked list, check if it is a palindrome or not.


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


    void reverseDLL(Node* &head, Node* &tail)
    {
        Node* currPtr = head;

        while(currPtr)
        {
            Node* nextPtr = currPtr->next;
            currPtr->next = currPtr->prev;
            currPtr->prev = nextPtr;
            currPtr = nextPtr;
        }
        //swapping head and tail pointers.
        Node* newHead = tail;
        tail = head;
        head = newHead;

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

int main()
{
    Node* new_node = new Node(1);

    DoublyLinkedList dll;
    dll.head = new_node;
    dll.tail = new_node;

    dll.insertAtStart(2);
    dll.insertAtStart(3);
    dll.display();

    dll.insertAtEnd(4);
    dll.insertAtEnd(5);
    dll.display();

    dll.reverseDLL(dll.head, dll.tail);
    dll.display();
    
    return 0;
}
