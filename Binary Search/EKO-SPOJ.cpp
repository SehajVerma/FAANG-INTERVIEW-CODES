https://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool valid(ll *a,ll n,ll mid,ll m)
{
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		sum= sum+max(0ll,a[i]-mid);
	}
	if(sum>=m)
	return true;
	else
	return false;
}
int main() {
	// your code goes here
	ll n;
	ll m;
	cin>>n>>m;
	ll a[n];
	for(ll i=0;i<n;i++)
	cin>>a[i];
	
   sort(a,a+n);
   ll low=0;
   ll high=a[n-1];
   ll finalAns=0;
   while(low<=high)
   {
   	   ll mid=(low+high)/2;
   	   if(valid(a,n,mid,m))
   	   {
   	   	finalAns=mid;
   	   	low=mid+1;
   	   }
   	   else
   	   {
   	   	 high=mid-1;
   	   }
   }
   cout<<finalAns<<endl;
	
	return 0;
}
