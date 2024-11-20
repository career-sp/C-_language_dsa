#include <iostream>
#include <vector>
using namespace std;

int fibo(int n)
{
    if(n==0 || n==1)return n;

    return fibo(n-1) + fibo(n-2);
}

int main()
{
    cout<<"The n th fibbonacci no is : ";
    cout<<fibo(6000);
 
return 0;
} 