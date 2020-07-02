#include <iostream>
using namespace std;
int solve(int *a,int n)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(a[mid]<a[mid-1])
            return a[mid-1];
        if(a[mid]>a[mid+1])
           return a[mid];

        if(a[mid]>a[high])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
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
