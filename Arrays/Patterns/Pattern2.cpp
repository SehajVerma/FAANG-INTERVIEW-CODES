    1    
   121   
  12321  
 1234321 
123454321


#include <bits/stdc++.h>
using namespace std;
int main() {
   int row,col;
   cin>>row>>col;
   int k=0;
   int x = ceil(float(col)/2.0);
   for(int i=1;i<=row;i++)
   {
       k=0;
       for(int j=1;j<=col;j++)
       {
          
           if(j>=row+1-i && j<=row-1+i){
                j<=x? k++:k--;
                cout<<k;
           }
           else
           cout<<" ";
       }
       cout<<endl;
   }
}
