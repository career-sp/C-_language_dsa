#include <iostream>
#include <map>
using namespace std;


int main()
{
    // creating a map.
    map<int,string> directory_1;

    // map<string, int, greater<string>> directory_1; --> for descending order.

    // directory_1.insert(make_pair({"A", 9942})); --> this will not work, as make pair takes direct arguments.

    //directory_1.insert(make_pair("A", 9942));
    
    directory_1[3] = "C";
    directory_1[4] = "D";
    
    directory_1[1] = "A";
    directory_1[2] = "B";
  
    directory_1[5] = "D";


    //printing:
    for(auto elements:directory_1)
    {
        cout<<elements.first<<" - "<<elements.second<<endl;
    }

    auto itr = directory_1.lower_bound(6);
   
    //  cout<<directory_1[itr].first; --> this will not work.

    cout<<itr->first<<" "<<itr->second<<endl;
    return 0;
}