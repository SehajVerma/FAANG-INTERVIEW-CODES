https://www.geeksforgeeks.org/remove-minimum-coins-such-that-absolute-difference-between-any-two-piles-is-less-than-k/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    sort(a,a+n);
	    int count=0;
	    int temp=0;
	    int minn=0;
	    int result=INT_MAX;
	    for(int i=0;i<n;i++)
	    {
	        count=temp;
	        temp+=a[i];
	        int minn = a[i];
	        for(int j=n-1;j>i;j--)
	        {
	            if(a[j]-minn>k)
	            count+=a[j]-minn-k;
	        }
	        result=min(result,count);
	    }
	    cout<<result<<endl;
	}
	return 0;
}
