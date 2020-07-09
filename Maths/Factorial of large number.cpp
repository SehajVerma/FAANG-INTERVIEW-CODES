#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[10000];
	    int len=1;
	    arr[0]=1;
	    int x=0;
	    int carry=0;
	    int q=2;
	    while(q<=n)
	    {
	      x=0;
	      carry=0;
	      while(x<len)
	      {
	         int mul = arr[x]*q+carry;
	         arr[x]=mul%10;
	         carry = mul/10;
	  
	         x++;
	      }
	      while(carry!=0)
	      {
	          arr[len]=carry%10;
	          carry=carry/10;
	          len++;
	      }
	      q++;
	    }
	    for(int i=len-1;i>=0;i--)
	    {
	        cout<<arr[i];
	    }
	    cout<<endl;
	}
	return 0;
}
