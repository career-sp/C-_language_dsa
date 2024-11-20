/*
Question: Given the head of a linked list, remove the k-th node from the end of the list and return its head.

Note: i in previous question the position is given from the head of the linked list but here the position will be from the ending of the linked list.
*/

 
/*
if k is 3
and list is : 1 -> 2 -> 3 -> 4 -> 5
we have to delete 3 from the list.
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
    Node *head;

    linked_list()
    {
        head = NULL;
    }

    ~linked_list()
    {
        Node *current_node = head;
        Node *next_node;

        while (current_node != NULL)
        {
            next_node = current_node->next;
            delete current_node;
            current_node = next_node;
            cout << "destructor called" << endl;
        }
    }

    void insertAtTail(int value)
    {
        Node *new_node = new Node(value);
        if (head == NULL)
        {
            head = new_node;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << " NULL" << endl;
    }
};

void deleteNodeFromEnd(Node* &head, int k)
// we are assuming k is always less than or equal length of linkedList.
{
    Node* ptr1 = head;
    Node* ptr2 = head;

// move ptr2 by k steps ahead;

int count = k;
while(count--)
{
    ptr2 = ptr2->next;
}

//handeling the terminal cases.
if(ptr2 == NULL) //k is equal to length of linked list.
// we have to delete the head node.
{
    Node* temp = head;
    head = head->next;
    delete temp;
    return;
}

//now ptr2 is k steps ahead of ptr1;
// when ptr2 is at null (end of list), ptr1 will be at node to be deleted.

while(ptr2->next != NULL)
{
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
}

// now ptr1 is pointing to the node before kth node from the end.

Node* temp = ptr1->next;
ptr1->next = ptr1->next->next;

delete temp;
}

int main()
{
    linked_list ll1;
    
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);

    ll1.display();

    deleteNodeFromEnd(ll1.head, 3);

    ll1.display();


    return 0;
}


