#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arrow[n];
    for(int i=0;i<n;i++)
    cin>>arrow[i];
    int flag=0;
    stack<int>s;
    s.push(arrow[0]);
    for(int i=1;i<n;i++)
    {
        flag=0;
        while(!s.empty() && s.top()>0 && arrow[i]<0)
        {
            if(s.top()<(-1*arrow[i]))
              s.pop();
            else
            {
                 if(s.top()==(-1*arrow[i])){
                     flag=1;
                     s.pop();
                     break;
            }
                 else{
                     flag=1;
                     break;
                 }
            }
        }
        if(!flag)
        s.push(arrow[i]);
    }
    int k=s.size();
    int out[k];
    for(int i=k-1;i>=0;i--)
    {
        out[i]=s.top();
        s.pop();
    }
    for(int i:out)
    cout<<i<<" ";
}
