/*
Question : You are given an array of k linked_lists, each linked-list is sorted in ascending order. Merge all the linked-lists into one sorted linked list and return it.

hint: first we will merge two linked list, then we will merge with the third one.
*/


#include <iostream>
#include <vector>
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

Node* mergeLinkedList(Node* &head1, Node* &head2)  // this will return the head of the merged linkedList.
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


Node* mergeK_LinkedList(vector <Node*> &lists) //In this vector we will store heads of our linked_lists.
{
    if(lists.size() == 0)return NULL;
    while(lists.size()>1)
    {
        Node* mergedHead = mergeLinkedList(lists[0], lists[1]);
        lists.push_back(mergedHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }

    /*
    head1, head2, head3, head4
    1. head1 and head2 will be merged.
    head3, head4, mergedHead1
    2. head3 and head4 will be merged.
    mergedHead1, mergedHead2
    3. mergedHead1 and mergedHead2 will be merged.
    our final will be : mergedHead3.
    
    
    */

   return lists[0];
}

int main()
{
    linked_list ll_1, ll_2, ll_3;

    ll_1.insertAtTail(1);
    ll_1.insertAtTail(7);
    ll_1.insertAtTail(8);
    ll_1.insertAtTail(9);
    
    ll_2.insertAtTail(2);
    ll_2.insertAtTail(4);
    ll_2.insertAtTail(5);
    ll_2.insertAtTail(12);
    
    ll_3.insertAtTail(3);
    ll_3.insertAtTail(6);
    ll_3.insertAtTail(23);
    ll_3.insertAtTail(34);
    
    ll_1.display();
    ll_2.display();
    ll_3.display();

    // creating the vector.
    vector<Node* > lists;

    lists.push_back(ll_1.head);
    lists.push_back(ll_2.head);
    lists.push_back(ll_3.head);

    linked_list mergedList;

    mergedList.head = mergeK_LinkedList(lists);

    mergedList.display();
    return 0;
}
