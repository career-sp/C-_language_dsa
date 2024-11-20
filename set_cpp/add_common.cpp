#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{ 
int m,n;
cin>>n>>m;

vector<int> v1(n);
vector<int> v2(m);
cout<<"Vector 1:";
for(int i=0; i<n; i++)
{
    cin>>v1[i];
}

cout<<endl<<"Vector 2: ";
for(int i=0; i<m; i++)
{
    cin>>v2[i];
}

set<int> s1;
for(auto ele:v1)
{
    s1.insert(ele);
}

int sum_value = 0;
for(auto ele:v2)
{
    if(s1.find(ele) != s1.end())
    {
        sum_value += ele;
    }
}

cout<<"Ans : "<<sum_value;

}


