// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() 
{
    // Rectangular pattern
    int row = 3, col = 6;
   
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<" *";
        }
    cout<<endl;
    }
    
    cout<<"\n\n";
    cout<<"Rectangular Pattern : \n";
    // Rectangular pattern
    int row1 = 5, col1 = 6;
    
    for(int i=0; i<row1; i++)
    {
        if(i == 0 || i == row1 - 1)
        {
            for(int j = 0; j<col1; j++)
            {
                cout<<" *";
            }
        }
        else
        {
            cout<<" *";
            for(int k=0; k<col-2; k++)
            {
                cout<<"  ";
            }
            cout<<" *";
        }
        cout<<"\n";
    }
    
    cout<<"\n\n\n";
    
    
    cout<<"Triangle Pattern: \n";
    //Triangle Pattern
    
    int row2=7;
    for(int i=0; i<row2; i++)
    {   // this loop is for space
        for(int s=0; s<row2-i; s++)
        {
            cout<<"  ";
        }
        
        // this loop is for the * one the first side.
        for(int j=0; j<i; j++ )
        {
            cout<<" *";
        }
        
        for(int k=0; k<=i; k++)
        {
            cout<<" *";
        }
        
        cout<<endl;
    }
    
    
    
    return 0;
}
