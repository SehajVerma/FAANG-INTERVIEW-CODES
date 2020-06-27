#include <bits/stdc++.h>
using namespace std;
class meet
{
  public:
      int sp;
      int fp;
      int idx;
};
bool comp(meet m1,meet m2)
{
    if(m1.fp < m2.fp)
      return true;
    else
      //return m1.sp < m2.sp;
      return false;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    meet m[100];
        meet o[100];
	    int c=0;
	    int n;
	    cin>>n;
	    int s[n];
	    int f[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>f[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        m[i].sp=s[i];
	        m[i].fp=f[i];
	        m[i].idx=i+1;
	    }
	    sort(m,m+n,comp);
	    o[c]=m[0];
	    for(int i=1;i<n;i++)
	    {
	        if(o[c].fp != m[i].fp && o[c].fp <= m[i].sp)
	        {
	            c++;
	            o[c]=m[i];
	        }
	    }
	    for(int i=0;i<=c;i++)
	    {
	        cout<<o[i].idx<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
