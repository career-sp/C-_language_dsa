#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class doublyll
{
public:
    Node* head;
    Node* tail;

    doublyll()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int data)
    {
        Node* new_node = new Node(data);
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
    
    void insertAtTail(int data)
    {
        Node* new_node = new Node(data);

        if(tail == nullptr)
        {
            tail = new_node;
            head = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;

    }

    void insertAtAny(int position, int data)
    {
        Node* new_node = new Node(data);

        if(position <= 1)
        {
            insertAtHead(data);
            return;
        }

        Node* new_node = new Node(data);
        int count = 1;

        


    }

    void display()
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<" nullptr. "<<endl;

    }
};

int main()
{
    doublyll dll;

    dll.display();
    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.display();
    return 0;
}