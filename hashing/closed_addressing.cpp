// something is not implemented properly in this code. 
// it is not giving the expected output. Have a look on the find portion. And why should i include the algorithm header file, i want to use the find function of list function here.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Hashing
{
    vector<list<int>> hashtable;
    int buckets;
public:
    Hashing(int size)
    {   
        buckets = size;
        hashtable.resize(size);
    }

    int hashValue(int key)
    {
        return key%buckets; // division method for the function.
    }

    void add_key(int key)
    {
        int idx = hashValue(key);
        //this is a vector of linked list.
        hashtable[idx].push_back(key); // function of linked list.
    }

    // function for searching.
    list<int>::iterator search_key(int key)
    {
        int idx = hashValue(key);

        // using the find function to find the element in the hash_table.
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);

    }

    void delete_key(int key)
    {
        int idx = hashValue(key);
        if(search_key(key) != hashtable[idx].end()) //if it is true that means value is present.
        {
            hashtable[idx].erase(search_key(key));
            cout<<endl<<key<<" is deleted. \n";
        }
        else
        {
            cout<<"Key is not present in the hash_table. \n"<<endl;
        }

    }

};


int main()
{
    Hashing h(10);
    h.add_key(9);
    h.add_key(8);
    h.add_key(7);

    h.delete_key(10);
    h.delete_key(10);

    return 0;
}