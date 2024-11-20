#include <iostream>
#include <vector>
using namespace std;

int getSumRecursive(int n)
{
    if(n>=0 && n<=9)return n; // base case
    return getSumRecursive(n/10) + n%10;
}

int main()
{                            
cout<<"the sum is :";
cout<<getSumRecursive(555);

return 0;
}