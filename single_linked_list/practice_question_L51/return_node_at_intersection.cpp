/*
Question: Given the heads of two singly linked-lists headA and headB. return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

*/

/*
This is a two pointer type question.
*/

/*
Question: given 2 linked lists. tell if they are equal or not. Two linked lists are equal if they have the same data and the arrangement of data is also the same.
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

int getLength(Node* head)
{
    int length = 0;
    Node*temp = head;

    while(temp!=NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}


Node* moveHeadby_k(Node* head, int k) // moving the longer list by k steps.
{
    Node* temp = head;
    while(k--)
    {
        temp = temp->next;
    }
    return temp;
}

Node* getInterSection(Node* head1, Node* head2)
{
    // step 1: calculate the length of the two lists.
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    // step 2: find difference k, between linkedlist and move the longer list's pointer by k steps.

    Node* ptr1, *ptr2;

    if(l1>l2)
    {
        int k = l1-l2;
        ptr1 = moveHeadby_k(head1, k);
        ptr2 = head2;
    }
    else
    {
        //ll2 is longer.
        int k = l2-l1;
        ptr1 = head1;
        ptr2 = moveHeadby_k(head2, k);
    }

    //step3: compare ptr1 and ptr2 nodes.

    while(ptr1)
    {
        if(ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}

int main()
{
    linked_list ll1, ll2;
    
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);


    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    
    //linking two linked list.(next pointer after 7 of ll2 with next pointer after 3 of ll1)
    ll2.head->next->next = ll1.head->next->next->next;
    
    // 1 -> 2 -> 3 -> 4 -> 5 ->  NULL
    // 6 -> 7 -> 4 -> 5 ->  NULL

    Node* intersection = getInterSection(ll1.head, ll2.head);
    
    if(intersection)
    {
        cout<<"The intersection point is : "<<intersection->data<<endl;
    }
    else
    {
        cout<<" output : -1 "<<endl;
    }
    ll1.display();
    ll2.display();
    return 0;
}
