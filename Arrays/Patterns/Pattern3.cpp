ABCDCBA
ABC CBA
AB   BA
A     A

#include <bits/stdc++.h>
using namespace std;
int main() {
   int row,col;
   cin>>row>>col;
   char k='A';
   int x = ceil(float(col)/2.0);
   for(int i=1;i<=row;i++)
   {
       k='A';
       for(int j=1;j<=col;j++)
       {
           if(j<=row+1-i || j>=row-1+i){
                cout<<k;
           }
           else
           cout<<" ";
           j<x? k++:k--;
       }
       cout<<endl;
   }
}
