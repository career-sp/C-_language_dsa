/* 
Merge sort is a divide and conquere technique.
*/

#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a, vector<int> &b, vector<int> &result) // merge two sorted arrays.
{
    // {2,3,6,9}  {1,4,5,7,8}

    int i = 0, j = 0, k = 0;

    while (i != a.size() && j != b.size())
    {
        if (a[i] <= b[j]) // < for unstable and <= for stable.
        {
            result[k++] = a[i++];
        }
        else
        {
            result[k++] = b[j++];
        }
    }

    if (i == a.size()) // vector a is at the end.
    {
        while(j != b.size())
        {
            result[k++] = b[j++];
        }
    }

    if (j == b.size())  // vector b is at the end.
    {
        while(i != a.size())
        {
            result[k++] = a[i++];
        }
    }
    
}

void merge_sort(vector<int> &v)
{
    if(v.size() <= 1) return;  // base case

    int n = v.size();
    int n1 = n/2;
    int n2 = n - n1;

    vector<int>a(n1);
    vector<int>b(n2);

    for(int i=0; i<n1; i++) a[i] = v[i];
    for(int i=0; i<n2; i++) b[i] = v[i+n1];;

    // recursion logic.
    merge_sort(a);
    merge_sort(b);

    merge(a,b,v);
}

int main()
{
    // int arr1[] = {2, 3, 6, 9,11,18};
    // int arr2[] = {1, 4, 5, 7, 8};
    // int n1 = sizeof(arr1)/sizeof(arr1[0]);
    // int n2 = sizeof(arr2)/sizeof(arr2[0]);

    // vector<int> a(arr1, arr1+n1); // copying the whole arr1 into the vector a, n1 is the size of the arr1.
    // vector<int> b(arr2, arr2+n2);
    // vector<int> result(n1+n2);

    // merge(a, b, result);

    int arr[] = {11, 2, 10, 5, 3, 4, 77, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> result(arr, arr+n);

    merge_sort(result);

    cout << "The elements are : ";
    for (int ele : result)
    {
        cout << ele << " ";
    }

    return 0;
}
