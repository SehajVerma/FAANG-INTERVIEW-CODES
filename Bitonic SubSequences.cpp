#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
	    cin>>n;
		int *a = new int[n];
		vector<int>left(n,1);
		vector<int>right(n,1);
		for(int i=0;i<n;i++)
		cin>>a[i];

		left[0]=1;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(a[j]<a[i])
				left[i]=max(left[i],left[j]+1);
			}
		}
		right[n-1]=1;
		for(int i=n-2;i>=0;i--)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[j]<a[i])
				right[i]=max(right[i],right[j]+1);
			}
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			ans = max(ans,left[i]+right[i]-1);
		}
		cout<<ans<<endl;

		
	}
	return 0;
}
