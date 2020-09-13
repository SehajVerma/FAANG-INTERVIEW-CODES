   1   
  232  
 34543 
4567654



#include <bits/stdc++.h>
using namespace std;
int main() {
   int row;
   cin>>row;
   int k=0;
   for(int i=1;i<=row;i++)
   {
       k=i;
       for(int j=1;j<=2*row-1;j++)
       {
           if(j>=row+1-i && j<=row-1+i){
                cout<<k;
                j<row?k++:k--;
           }
           else
           cout<<" ";
       }
       cout<<endl;
   }
}
