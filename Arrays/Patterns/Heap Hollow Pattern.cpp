      *      
     * *     
    * * *    
   * * * *   
  * * * * *  
 * * * * * * 
* * * * * * *


#include <iostream>
using namespace std;
int main() {
   int row,col;
   cin>>row>>col;
   int k=1;
   for(int i=1;i<=row;i++)
   {
       for(int j=1;j<=col;j++)
       {
           if(k && j>=row+1-i && j<=row-1+i)
           cout<<"*",k=0;
           else
           cout<<" ",k=1;
       }
       cout<<endl;
   }
}

