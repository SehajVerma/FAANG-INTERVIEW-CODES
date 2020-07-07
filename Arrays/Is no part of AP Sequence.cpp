https://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/

#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    double a,b,c;
	    cin>>a>>b>>c;
	    int x = floor((b-a)/c);
	    int y = ceil((b-a)/c);
	    if((a==b) || (x==y && y>=0))
	    cout<<"1"<<endl;
	    else
	    cout<<"0"<<endl;
	}
	return 0;
}
