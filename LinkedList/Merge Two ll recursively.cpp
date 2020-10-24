#include <bits/stdc++.h>
using namespace std;
int mergeTwosortedList(Node* h1,Node* h2)
{
    if(h1==NULL)
    return h2;

    if(h2==NULL)
    return h1;

   if(h1->data < h2->data)
   {
       h1->next = mergeTwosortedList(h1->next,h2);
       return h1;
   } 
   else
   {
       h2->next = mergeTwosortedList(h1,h2->next);
       return h2;
   }
}
