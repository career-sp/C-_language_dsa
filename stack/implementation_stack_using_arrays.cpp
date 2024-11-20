/*
Stack Implementation using Arrays.
Here our push, pop and other functions must be implemented in constant time complexity. Which is O(1).

*/
#include <iostream>
#include <climits> 
// this library we should include for using  INT_MIN

using namespace std;

class stack
{   // properties of stack.
    int capacity;
    int *arr;
    int top;

public:
//some methods of stack.
    stack(int capacity)                 // creating a stack object.
    {
        this->capacity = capacity;
        arr = new int[this->capacity]; 
        // we are creating array by dynamic memory allocation.
        this->top = -1;
    }

    void push(int data)                   // push operation in stack.
    {
        if(this->top == capacity - 1)
        {
            cout<<"over flow"<<endl;
            return;
        }
        this->top++;
        this->arr[this->top] = data;

    }

    int pop()                           // pop operation in stack.
    {
        if(this->top == -1)
        {
            cout<<"Under flow"<<endl;
            return INT_MIN;
        }
        return this->arr[this->top--]; //return the popped value.
    }

    int topElement()                   // return the top element in the stack.
    {
        if(this->top == -1)
        {
            cout<<"Under flow"<<endl;
            return INT_MIN;
        }
        return (this->arr[this->top]);
    }

    bool isEmpty()                  // checking if stack is empty or not.
    {
        return this->top == -1;
    }

    int size()                      // calculating the size of the stack.
    {
        return this->top + 1;
    }

    bool isFull()                   // checking if stack is full or not.
    {
        return this->top == (this->capacity -1);
    }

    void display()
    {
        if(isEmpty())
        {
            cout<<" The stack is empty."<<endl;
            return;
        }
        for(int i=0; i<=this->top; i++)
        {
            cout<<this->arr[i]<<" ";
        }
        cout<<" endl of the stack."<<endl;
    }

};



int main()
{
    stack st(4);

    st.push(1);
    st.push(2);
    st.push(3);

    st.display();

    st.pop();

    st.display();
    cout<<st.topElement()<<endl;
    return 0;
} 