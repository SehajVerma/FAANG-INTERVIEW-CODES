https://www.spoj.com/problems/PRATA/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool valid(ll *a,ll c,ll mid,ll p)
{
	ll parantha = 0;
	for(ll i=0;i<c;i++)
	{
		ll m = a[i];
		ll x = 2;
		while(m<=mid)
		{
			parantha++;
			if(parantha>=p) return true;
			
			m+=x*a[i];
			x++;
		}
	}
	return false;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		ll p;
		ll c;
		cin>>p>>c;
		ll a[c];
		for(ll i=0;i<c;i++)
		cin>>a[i];
		
	   sort(a,a+c);
	   ll low=0;
	   ll high=100000000;
	   ll finalAns=0;
	   while(low<=high)
	   {
	   	   ll mid=(low+high)/2;
	   	   if(valid(a,c,mid,p))
	   	   {
	   	   	finalAns=mid;
	   	    high=mid-1;
	   	   }
	   	   else
	   	   {
	   	   	low=mid+1;
	   	   }
	   }
	   cout<<finalAns<<endl;
	}
	
	return 0;
}
