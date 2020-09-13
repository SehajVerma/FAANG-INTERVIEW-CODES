A            
BA          
CBA        
DCBA      
EDCBA    
FEDCBA  
GFEDCBA



#include <bits/stdc++.h>
using namespace std;
int main() {
   int row;
   cin>>row;
   int m=0;
   for(int i=1;i<=row;i++)
   {
       m=64+i;
       for(int j=1;j<=row;j++)
       {
           if(j<=i){
           cout<<(char)m;
           m--;
           }
           else
           cout<<"  ";
       }
       cout<<endl;
   }
}
