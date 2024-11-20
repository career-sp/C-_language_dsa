/*
Question: 
Sum of Repetitive Elements.
You are given an integer n, representing the number of elements. Then, you will be given a n elements. You have to return the sum of repetitive elements i.e. the elements that appear more than one time.

input:
n = 7
elements = [1,1,2,1,3,3,3]

output: 4

*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main()
{
    int n;
    cout<<"Enter : ";
    cin>>n;
    cout<<endl;

    vector<int> input(n); // creating vector of size n.

    cout<<"\n Enter elements : ";
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }

    cout<<endl;

    map<int,int> m;
    for(int i=0; i<n; i++)
    {
        m[input[i]]++; // main logic --> used to calculate the frequency of every element.
    }

    int sum=0;

    for(auto element:m)
    {
        if(element.second > 1)
        {
            sum += element.first;
        }
    }

    cout<<"\n\n The sum = "<<sum;
    return 0;
}