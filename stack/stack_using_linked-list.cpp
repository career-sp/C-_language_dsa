/*

Stack Implementation using Linked_list.

we have access of the head in linked_list at any moment.
 
Now we have to make the head as top.

push: insert at head.
pop: remove from head.

isEmpty: head == NULL.
under flow: head == NULL.

top: return the element at head.
over flow: take one variable size, when push, size++, when pop      size--. Now if current size is equal to max_capacity then overflow.

Note:
all implementation must have constant time complexity.

*/

#include <iostream>
#include <climits>

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


class stack
{
    Node * head;
    int capacity;
    int currSize;
public:
    stack(int capacity)
    {
        this->capacity = capacity;
        this->currSize = 0;
        head = NULL;
    }

    bool isEmpty()
    {
        return this->head == NULL;
    }

    bool isFull()
    {
        return this->currSize == this->capacity;
    }

    void push(int data)
    {
        if(this->currSize == this->capacity)
        {
            cout<<"Over Flow"<<endl;
            return;
        }
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        currSize++;
    }

    int popNode()
    {
        if(this->head == NULL)
        {
            cout<<"Under Flow"<<endl;
            return INT_MIN;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

int main()
{





    return 0;
}
