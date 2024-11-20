#include <iostream>
using namespace std;

template <typename T>
class Node // this is called a templete class.
{
public:
    T val;
    Node* next;

    Node(T data)
    {
        val = data;
        next = nullptr;
    }
};


int main()
{
    //Node<int> node1(3);
    //normally.
    // Node* node1 = new Node(3);
    Node<int>* node1 = new Node<int>(33);
    cout<<node1->val<<endl;

    Node<char>* node2 = new Node<char>('H');
    cout<<node2->val;

    return 0;
}