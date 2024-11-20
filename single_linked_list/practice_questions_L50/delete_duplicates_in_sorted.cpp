/*Question:

    Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Hint: if the values of current_node and the current_node->next are equal then delete the current_node->next. 

we also need multiple while loops.

Note : the time complexity of this question will be O(n)
*/

/*
while(current_node != NULL) or we can also write here while(current_node) --- as if it become null the it will end the while loop.

    while(current_node->value == current_node->next->value  
            && current_node->next != NULL)
        //remove current->next node.
    
    update the current_node to current_node ->next.
*/


#include <iostream>
using namespace std;

class Node              //creating a class for nodes.
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

class linkedList        //creating a class for linked list.
{
    // here the property of the linkedList will be head.
    // As we could access the whole linkedList using the head.
public:
    Node* head;

    linkedList()
    {
        head = NULL;
    }

    ~linkedList()       // creating a destructor for better memory management.
    {
        Node* current_Node = head;
        Node* next_Node;

        while(current_Node != NULL)
        {
            next_Node = current_Node->next;
            delete current_Node;
            current_Node = next_Node;

        } 
    }

    void inserAtTail(int value)
    {   
        Node* new_node = new Node(value);
        if(head == NULL)
        {
            head = new_node;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        //now we are at the last node.
        temp->next = new_node;
    }

    void display(){  
    // we do not have to pass the parameter Node* head as we are inside the class.
    Node* temp = head;
    while(temp != NULL)
    {   
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<" NULL"<<endl;
    }


};

void deleteDuplicateNodes(Node* head)               // function for deleting duplicate nodes.
{
    Node* curr_node = head;

    while(curr_node)
    {
        while(curr_node->next != NULL && curr_node->data == curr_node->next->data)
        // Note. - we must write curr_node->next != NULL condition before checking the values of two nodes.
        // or it will through an error.
        {
            // we will delete our next node value.
            Node* temp = curr_node->next;
            curr_node->next = curr_node->next->next;
            delete temp;
        }
        curr_node = curr_node->next;
    }
    
}

int main()
{
linkedList ll;
int choice, data, position;

while(true)
{
    cout<<"# LINKED LIST PRACTICE : "<<endl; 
    cout<<"1. Insert at the End."<<endl;
    cout<<"2. to display."<<endl;
    cout<<"3. Delete duplicate nodes."<<endl;
    
    cout<<"any other. to exit."<<endl<<endl;

    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"Enter the value : ";
            cin>>data;
            ll.inserAtTail(data);
            break;
        case 2:
            ll.display();
            break;
        case 3: 
            deleteDuplicateNodes(ll.head);
            break;
        default:
            cout<<"Program Ended."<<endl;
            return 0;   
    }
}

return 0;
}
