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
        this->data;
        prev = nullptr;
        next = nullptr;
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
        if(head == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;

    }

    void insertAtend(int data)
    {
        Node* new_node = new Node(data);
        if(tail == nullptr)
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

    void insertAtPosition(int data, int position)
    {
        if(position <= 1)
        {
            insertAtHead(data);
            return;
        }

        int count = 1;
        Node* temp = head;
        while(count != position-1)
        {
            temp = temp -> next;
            count++;
        }
        Node* new_node = new Node(data);

        new_node->next = temp->next;
        temp->next = new_node;

        new_node->prev = temp;
        new_node->next->prev = new_node;
        return;
    }


};
