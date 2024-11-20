#include <iostream>
#include <set>
using namespace std;

int main()
{
//set<int> set1;   // by default it is in increasing order.
set<int, greater <int>> set1; // setting the values in descending order.

set1.insert(2);
set1.insert(3);
set1.insert(8);
set1.insert(4);
set1.insert(2);  // it will not take same value multiple times.
set1.insert(2);

// set<int>::iterator itr;

// for(itr=set1.begin(); itr!=set1.end(); itr++)
// {
//     cout<<*itr<<" ";
// }


// i could also use iterator using the auto keyword.
for(auto itr=set1.begin(); itr!=set1.end(); itr++)
{
    cout<<*itr<<" ";
}
cout<<endl;


// iterate using for each loop.

for(auto value:set1)
{
    cout<<value<<" ";
}
cout<<"Max size: ";
cout<<set1.max_size()<<endl;


// search operation.
if(set1.find(4) != set1.end())
{  
    cout<<*(set1.find(4))<<endl;
}

}
