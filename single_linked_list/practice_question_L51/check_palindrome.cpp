/*
Question:
Given head, the head of a linked list, determine if the liked list is a palindrome or not.

even nodes:
1. step 1: find the middle element.
2. step 2: break linked list or separate linked list.
3. step 3: reverse second half of the linked list.
4. compare the 2 part of linked list.

odd nodes:

*/


#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

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

bool detectCycle(Node* head)
{
    if(!head) // check if our head is empty or not.
    {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast !=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        // cout<<"fast :"<<fast->data<<" Slow : "<<slow->data<<endl;
        if(slow == fast)
        {
            return true;
        }
    }

    return false;    
}

int main()
{
    linked_list ll_1;
    ll_1.insertAtTail(1);
    ll_1.insertAtTail(2);
    ll_1.insertAtTail(3);
    ll_1.insertAtTail(4);
    ll_1.insertAtTail(5);
    ll_1.insertAtTail(6);
    ll_1.insertAtTail(7);
    ll_1.insertAtTail(8);

    ll_1.display();

    // creating cycle.

    ll_1.head->next->next->next->next->next->next->next->next = ll_1.head->next->next;
    cout<<endl;
    cout<<detectCycle(ll_1.head)<<endl;

    return 0;
}
