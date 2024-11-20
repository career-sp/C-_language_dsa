/*
Pattern: Slow fast pointer.

question: find the middle element of the given linked list.

Note: one way of doing this is to traverse the linked list and find out the length then find the middle.

but if the interviewer said that you are not allowed to traverse the linked list twice. -->


Hint: we will use the two pointers.
slow: ptr1 = ptr->next;
fast: ptr2 = ptr->next->next;

# when the ptr2 reach the end of our linked list at the same time the ptr1 will be at the middle of the linked list. 

## 2 cases for stopping :

even nodes: when the fastptr == NULL
odd nodes: when the fastptr->next == NULL

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

Node* findMiddleNode(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    linked_list ll_1;
    int choice, data;

    while (true)
    {
        cout << "1 for insertAtTail of linked list 1." << endl;
        cout << "2 Display the linked list 1." << endl;
        cout << "3 Return the middle element." << endl;
        cout << "Enter any other to exit." << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value : ";
            cin >> data;
            ll_1.insertAtTail(data);
            break;
        case 2:
            ll_1.display();
            break;
        case 3:
            cout<<"The middle element of my Linked_list is : ";
            cout<<findMiddleNode(ll_1.head)->data<<endl;
            break;
        default:
            cout << "program ended." << endl;
            return 0;
        }
    }

    return 0;
}
