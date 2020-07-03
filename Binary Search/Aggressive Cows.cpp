Problem - https://www.spoj.com/problems/AGGRCOW/
Solution - https://www.youtube.com/watch?v=TC6snf6KPdE

#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool valid(ll *a,ll n,ll mid,ll c)
{
	ll cows=1;
	ll s=a[0];
	ll i=0;
	while(i<n-1)
	{
		if(s+mid<=a[i+1])
		{
		  s=a[i+1];
		  cows++;
		  if(cows==c)
		    return true;
		}
	    i++;
	}
	return false;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		ll c;
		cin>>n>>c;
		ll a[n];
		for(ll i=0;i<n;i++)
		cin>>a[i];
		
	   sort(a,a+n);
	   ll low=0;
	   ll high=a[n-1]-a[0];
	   ll finalAns=0;
	   while(low<=high)
	   {
	   	   ll mid=(low+high)/2;
	   	   if(valid(a,n,mid,c))
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
	}
	
	return 0;
}
