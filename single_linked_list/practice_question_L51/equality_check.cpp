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

bool checkEquality(Node* head1, Node* head2)
{
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->data != ptr2->data)return false;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return (ptr1 == NULL && ptr2 == NULL);
}

int main()
{
    linked_list ll_1, ll_2;
    int choice, data;

    while (true)
    {
        cout << "1 for insertAtTail of linked list 1." << endl;
        cout << "2 for insertAtTail of linked list 2." << endl;
        cout << "3 Display the linked list 1 & 2." << endl;
        cout << "4 Check if both of the linked list are equal or not." << endl;
        cout << "Enter any other to exit." << endl;

        cout << "Enter your choice : " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value : ";
            cin >> data;
            ll_1.insertAtTail(data);
            break;
        case 2:
            cout << "Enter value : ";
            cin >> data;
            ll_2.insertAtTail(data);
            break;
        case 3:
            ll_1.display();
            ll_2.display();
            break;
        case 4:
            cout<<"The result of equality check : ";
            cout<<checkEquality(ll_1.head, ll_2.head)<<endl;
            break;
        default:
            cout << "program ended." << endl;
            return 0;
        }
    }

    return 0;
}
