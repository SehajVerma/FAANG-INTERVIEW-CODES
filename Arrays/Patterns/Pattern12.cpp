1     
6 2    
10 7 3   
13 11 8 4  
15 14 12 9 5 



#include <bits/stdc++.h>
using namespace std;
int main() {
   int row;
   cin>>row;
   int p=1,q=1;
   int k=0;
   int r=row;
   for(int i=1;i<=row;i++)
   {
       for(int j=1;j<=row;j++)
       {
           if(j<=i)
           {
               cout<<q<<" ";
               q=q-k;
               k++;
           }
           else
           cout<<" ";
       }
       p=p+r--;
       q=p;
       k=r;
       cout<<endl;
   }
}
