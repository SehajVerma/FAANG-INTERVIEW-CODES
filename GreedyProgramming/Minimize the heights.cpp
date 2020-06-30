https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int k,n;
	    cin>>k>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    sort(a,a+n);
	    int ans=a[n-1]-a[0];
	    int small = a[0]+k;
	    int big = a[n-1]-k;
	    if(small>big)
	    swap(small,big);
	    for(int i=1;i<n-1;i++)
	    {
	        int subtract = a[i]-k;
	        int add = a[i]+k;
	        
	        if(subtract >= small || add <= big)
	        continue;
	        
	        if(big-subtract <= add-small)
	        small = subtract;
	        else
	        big = add;
	    }
	    cout<<min(ans,big-small)<<endl;
	}
	return 0;
}
