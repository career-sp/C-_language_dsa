/*
## slow and fast pointer.
here are two questions in one.

Question: 
Given head, the head of a linked list, determine if the linked list has a cycle in it.

Note: cycle present means, 
        22 -> 33 -> 44 -> 55 -> 6 -> 77 -> 88 ->  NULL
            # now here if 88 is pointing to 44. 

hint: if a = x  and speed of b =  2x , how it is possible that a and b starts at same time but after some time they meet. how it is possible.

If fast and slow ponter meet anyWhere then we can say there exists a cycle.
*/

/*
Question:
Now after finding out that there is a loop present in our linked list. the interviewer asked us to remove the cycle.

Hint: we use floyd's algorithm.
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
