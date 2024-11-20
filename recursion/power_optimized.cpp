/*
Time complexity of this code is of O(log q)
*/


#include <iostream>
#include <vector>
using namespace std;

int get_power_optimised(int p, int q)
{
if(q == 0) return 1;
    if(q%2 == 0)  //even case
    {
        int result = get_power_optimised(p, (q/2));
        return result*result;
    }
    else  // odd case
    {
        int result = get_power_optimised(p, (q-1)/2);
        return (result*result)*p;
    }

}

int main()
{
int n=5;

cout<<get_power_optimised(6,2);

return 0;
}