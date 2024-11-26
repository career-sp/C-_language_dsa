/*
In selection sort there are (n-1) swaps.
but in bubble sort there are n(n-1)/2 swaps.
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(vector<int> &arr)
{
    int n = arr.size();

    for(int i=0; i<n-1; i++)
    {
        int min = INT_MAX;
        int min_idx = -1; // as here it does not exist.
        for(int j=i; j<n; j++)
        {
            if(arr[j]<min)
            {
                min = arr[j];
                min_idx = j;
            } 
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main()
{
cout<<"Enter the size:";
int n;
cin>>n;
vector<int> arr(n);

cout<<"Enter the elements : ";
for(int i=0; i<n; i++) cin>>arr[i];

selection_sort(arr);

cout<<"the elements after sorting : ";
for(int i=0; i<n; i++) cout<<arr[i]<<" ";

return 0;

}