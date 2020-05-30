#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int k;
	cin>>k;
	deque<int>dq;
	int sum[n];
	sum[0]=a[0];
	for(int i=1;i<n;i++)
	{
		sum[i]=a[i]+sum[i-1];
	}
	int length=INT_MAX;
	for(int i=0;i<n;i++)
	{
		while(!dq.empty() && sum[i]-sum[dq.front()]>=k)
		{
			length=min(length,i-dq.front());
			dq.pop_front();
		}
		while(!dq.empty() && sum[i]-sum[dq.back()]<=0) 
		   dq.pop_back();

		dq.push_back(i);
	}
	if(length!=INT_MAX)
	cout<<length;
	else
	cout<<0;
}
