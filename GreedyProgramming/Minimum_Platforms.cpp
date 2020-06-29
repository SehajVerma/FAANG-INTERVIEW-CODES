in brute force 0(n*n)  
in optimized we sort both arrival and departure
max one platform is needed
we see if arrival is less than departure we increase max_platform
this means that abhi trains aayi ja rhi hai koi platform leave ni kr rhi
jaise he train platform leave kre i.e departure is less than arrival pmax_platform decrease hote rhenge


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    int dep[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    for(int i=0;i<n;i++)
	    cin>>dep[i];
	    sort(arr,arr+n);
	    sort(dep,dep+n);
	    int max_plat = 1;
	    int plat_need = 1;
	    int i=1,j=0;
	    while(i<n && j<n)
	    {
	       if(arr[i]>dep[j])
	       {
	           j++;
	           max_plat--;
	       }
	       else
	       {
	           i++;
	           max_plat++;
	           plat_need = max(max_plat,plat_need);
	       }
	    }
	    cout<<plat_need<<endl;
	}
	return 0;
}
