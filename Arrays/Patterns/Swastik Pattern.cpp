*   * * * 
*   *     
* * * * * 
    *   * 
* * *   * 


#include <bits/stdc++.h>
using namespace std;
int main() {
   int row;
   cin>>row;
   int x=(row+1)/2;
   for(int i=1;i<=row;i++)
   {
       for(int j=1;j<=row;j++)
       {
           if(i==x || j==x)
           {
               cout<<"* ";
           }
           else
           {
               if((i<x && j==1) || (i==1 && j>x) || (i>x && j==row) || (i==row && j<x))
               cout<<"* ";
               else
               cout<<"  ";
           }
       }
       cout<<endl;
   }
}
