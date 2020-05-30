#include <bits/stdc++.h>
using namespace std;
int next(int *a,int n,int i)
{
    return (i+a[i]+n)%n;
}
int array_loop(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        int slow = i;
        int fast = i;
        if(a[i]==0)
        continue;

        while(a[slow]*a[next(a,n,slow)]>0 && a[fast]*a[next(a,n,fast)]>0 &&
               a[fast]*a[next(a,n,next(a,n,fast))]>0){
               
               slow=next(a,n,slow);
               fast=next(a,n,next(a,n,fast));
               if(fast==slow)
               {
                   if(slow==next(a,n,slow))
                   break;

                   return 1;
               }
            }
            // slow = i;
            // int val=a[slow];
            // while(val*a[slow]>0)
            // {
            //     int x=slow;
            //     slow = next(a,n,slow);
            //     a[x]=0;
            // }
    }
    return 0;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<array_loop(a,n);
}
