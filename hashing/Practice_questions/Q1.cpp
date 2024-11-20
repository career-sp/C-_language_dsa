/*
Can you make the stirngs equal?

Given an array of strings. You can move any number of characters from one strng to any other string any number of times. You just have to make all of them equal.

Print "yes" if you can make every string in the array equal by using any number of operations otherwise print "No".

e.g. 
    input: ["collegee", "coll", "collegge"]
    output: yes. 

    input: ["wall", "ah", "wallahah"]
    output: No
    explanation: here we don't have enough no of elements.

points: 
1) we don't need to transform strings by moving elements.                                                   
2) Each character should be multiples of n, where n is the no of strings in our array.(length of array)

Time complexity: O(N)--> where N is the number of all characters. 

Space complexity: O(M) --> where M is the no of unique characters.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool canMakeEqual(vector<string> &vec)
{
    unordered_map<char, int> list_1;

    for(string element:vec) // calculating the frequency.
    {
        for(char c:element)
        {
            list_1[c]++;
        }
    }

    int m = vec.size(); 

    for(auto ele:list_1)
    {
        if(ele.second % m != 0)
        {
            return false;
        }
    }

    return true;
}


int main()
{
    int n;
    cout<<"Enter no of strings : ";
    cin>>n;

    vector<string> str_list(n);

    cout<<"\nEnter your strings :";
    
    for(int i=0; i<n; i++)
    {
        cin>>str_list[i];
    }
    cout<<endl;

    cout<<(canMakeEqual(str_list)? " Yes ": "No");

    return 0;
}






