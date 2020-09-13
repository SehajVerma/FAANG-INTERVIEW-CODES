6543210
543210 
43210  
3210   
210    
10     
0



#include <bits/stdc++.h>
using namespace std;
int main() {
   int row;
   cin>>row;
   int k=0;
   for(int i=1;i<=row;i++)
   {
       k=row-i;
       for(int j=1;j<=row;j++)
       {
           if(j<=row+1-i){
                cout<<k;
                k--;
           }
           else
           cout<<" ";
       }
       cout<<endl;
   }
}
