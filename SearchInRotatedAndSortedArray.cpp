#include <bits/stdc++.h>
using namespace std;
int print(int *a,int k,int s,int e)
{
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==k)
        return mid;
        if(a[mid]<=a[e])
        {
            if(k>a[mid] && k<=a[e])
            s=mid+1;
            else
            e=mid-1;
        }
        else
        {
                if(k>=a[s] && k<a[mid])
                e=mid-1;
                else
                s=mid+1;
        }
    }
    return -1;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int k;
	    cin>>k;
	    cout<<print(a,k,0,n-1)<<endl;
	}
	return 0;
}
