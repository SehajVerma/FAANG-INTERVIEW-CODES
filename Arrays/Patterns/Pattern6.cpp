    1
   12
  123
 1234
12345
 1234
  123
   12
    1
    
#include <bits/stdc++.h>
using namespace std;
int main() {
   int row;
   cin>>row;
   int k=0,m=0;
   int x = (row+1)/2;
   for(int i=1;i<=row;i++)
   {
       i<=x ? k++ : k--;
       m=1;
       for(int j=1;j<=x;j++)
       {
           if(j>=(x+1-k)){
                cout<<m;
                m++;
           }
           else
           cout<<" ";
       }
       cout<<endl;
   }
