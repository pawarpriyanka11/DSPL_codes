/*You are given an integer array 'A' of size 'N', sorted in non- decreasing order. You are also given an integer 'target'. Your task
is to write a function to search for 'target' in the array 'A'. If it
exists, return its index in 0-based indexing using Linear Search in
C++/Python/Java.*/

#include<iostream>
using namespace std;
class search
{
    public:
    int f=0;
    void find(int a[],int n,int target)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]==target)
            {
                cout<<"\nElement found at position: "<<i;
                f=1;
                break;
            }
        
        }
        if(f==0)
        {
            cout<<"\nelement not found!";
        }
    }
   

};
int main()
{
    search s;
    int n,*a,target;
     cout<<"\nEnter number of  array elements:";
     cin>>n;
     a=new int[n];
     cout<<"\nEnter array elements:";
     for(int i=0;i<n;i++)
     {
        cin>>a[i];
     }
     cout<<"\nEnter the target: ";
     cin>>target;
     s.find(a, n, target); 
     delete[] a;  
     return 0;
}