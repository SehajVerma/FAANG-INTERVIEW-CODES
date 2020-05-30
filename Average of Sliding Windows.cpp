#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    int n;
    deque<int>dq;
    int i=1;
    int flag=0;
    double avg=0;
    double sum=0;
    while(i!=(k+1))
    {
        cin>>n;
        if(n==-1){
        flag=1;
        break;
        }
        dq.push_back(n);
        sum=sum+n;
        avg=sum/i;
        i++;
        cout<<avg<<" ";
    }
    if(!flag)
    {
        cin>>n;
        while(n!=-1)
        {
            dq.push_back(n);
            sum=sum+n-dq.front();
            dq.pop_front();
            avg=sum/k;
            cout<<avg<<" ";
            cin>>n;
        }
    }
    
}
