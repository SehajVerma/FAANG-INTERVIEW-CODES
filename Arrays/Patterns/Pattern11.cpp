         1         
        A B        
       1 2 3       
      A B C D      
     1 2 3 4 5     
    A B C D E F    
   1 2 3 4 5 6 7   
  A B C D E F G H  
 1 2 3 4 5 6 7 8 9 
A B C D E F G H I J


#include <bits/stdc++.h>
using namespace std;
int main() {
   int row;
   cin>>row;
   int k=0;
   int m=0;
   for(int i=1;i<=row;i++)
   {
       if(i%2)
       m=49;
       else
       m=65;
       for(int j=1;j<=2*row-1;j++)
       {
           if(k && j>=row+1-i && j<=row-1+i){
           cout<<(char)m++;
           k=0;
           }
           else{
           cout<<" ";
           k=1;
           }
       }
       cout<<endl;
   }
}
