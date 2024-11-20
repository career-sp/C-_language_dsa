#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
int n;
cout<<"enter no of values : ";
cin>>n;
cout<<endl;
vector<int> v(n); //creating the vector.
cout<<"Enter the elements: ";
for(int i=0; i<n; i++)
{
    cin>>v[i];
}

set<int> s;
for(auto value: v)
{
    s.insert(value);
}

auto itr = s.begin();
// advance(itr, 1);
itr++;

cout<<"the value is : "<<*itr;
return 0;
}