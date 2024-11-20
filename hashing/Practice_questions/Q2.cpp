/*
Check whether two strings are  anagram of each other. Return true if they are else return false.

An anagram of a string is another string that contains the same characters, only the order of characters can be different. 

For example: 
1)"abcd" and "dabc"
2) triangle and integral

time complexity: O(N) --> sum of the length of s1 & s2
space complexity: O(n) --> length of the string.

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool checkAnagram(string &s1, string &s2)
{
    unordered_map<char,int> m;

    for(auto c: s1)
    {
        m[c]++;
    }

    for(auto c: s2)
    {
        if(m.find(c) == m.end())
        {
            return false;
        }
        else
        {
            m[c]--;
        }
    }

    for(auto key:m)
    {
        if(key.second != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s1, s2;

    cout<<"Enter the string 1 :";
    cin>>s1;

    
    cout<<"\n\nEnter the string 2 :";
    cin>>s2;

    cout<<endl;
    cout<<(checkAnagram(s1,s2) ? "Yes It's a anagram.": "Not Anagram.");

    return 0;
}

