#include <bits/stdc++.h>
using namespace std;
int solve(int *a,int n)
{
    int d = min(a[1]-a[0],a[2]-a[1]);
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if((a[mid]-a[mid-1])!=d)
        return a[mid]-d;
        if((a[mid+1]-a[mid])!=d)
        return a[mid+1]-d;
        
        if(a[0]+mid*d < a[mid])
        high=mid-1;
        else
        low=mid+1;
    }
    return 0;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<solve(a,n);
}
