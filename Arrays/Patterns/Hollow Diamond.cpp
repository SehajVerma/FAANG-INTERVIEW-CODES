   #   
  # #  
 #   # 
#     #
 #   # 
  # #  
   #  



#include <bits/stdc++.h>
using namespace std;
int main() {
   int row;
   cin>>row;
   int x=(row+1)/2;
   int k=0;
   for(int i=1;i<=row;i++)
   {
       i<=x?k++:k--;
       for(int j=1;j<=row;j++)
       {
           if(j==x+1-k || j==x-1+k)
           cout<<"#";
           else
           cout<<" ";
       }
       cout<<endl;
   }
}
