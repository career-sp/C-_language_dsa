/*
Question : Given two sorted linked lists, merge them into one singly linked list such that the resulting list is also sorted.

doubt: line 153. why we neede to give the extra patenthesis there, and why the destructor is being called there.
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

Node* mergeLinkedList(Node* head1, Node* head2)  // this will return the head of the merged linkedList.
{//here need to pass by reference as we are creating another linked list where we are storing the merged linked list.
    Node* dummyHeadNode = new Node(-1);  // creating a dummy node to simplify merging.

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyHeadNode;

    while(ptr1 && ptr2)
    {
        if(ptr1->data < ptr2->data)  // smaller node will be inserted.
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next; // as the value of the ptr1 has been inserted.
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next; 
    }

    if(ptr1)
    {
        ptr3->next = ptr1;
    }
    else
    {
        ptr3->next = ptr2;
    }

    return dummyHeadNode->next; // this will be the head of our merged linked list.
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
        cout << "4 give the merged linked linked list." << endl;
        cout << "Enter any other to exit." << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice)
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
            {
                linked_list list3;
                list3.head = mergeLinkedList(ll_1.head, ll_2.head);
                list3.display();
                break;  // after execution of this line destructor will automatically called. doubt.
            } //this {} is needed here to prevent malfunction of the program.
            default:
                cout << "program ended." << endl;
                return 0;
        }
    }

    return 0;
}
