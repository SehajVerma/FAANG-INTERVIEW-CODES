     A
    CB
   FED
  JIHG
 ONMLK
UTSRQP



#include <bits/stdc++.h>
using namespace std;
int main() {
   int row;
   cin>>row;
   int m=64,p=0;
   for(int i=1;i<=row;i++)
   {
       m=m+i;
       p=m;
       //k='A'+2*(i-1) +1; can do this job
       for(int j=1;j<=row;j++)
       {
           if(j>=row+1-i){
           cout<<(char)p;
           p--;
           }
           else
           cout<<" ";
       }
       cout<<endl;
   }
}
