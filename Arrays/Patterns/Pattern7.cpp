\*****/
*\***/*
**\*/**
***/***
**/*\**
*/***\*
/*****\

#include <bits/stdc++.h>
using namespace std;
int main() {
   int row;
   cin>>row;
   for(int i=1;i<=row;i++)
   {
       for(int j=1;j<=row;j++)
       {
           if((i+j)==row+1)
           cout<<"/";
           else if(i==j)
           cout<<"\\";
           else
           cout<<"*";
       }
       cout<<endl;
   }
}
