#include <bits/stdc++.h>
using namespace std;
#define dude ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
const int N=50000+5;
class node
{
  public:
	ll pfx,suf,sum,best;
	node()
	{
		pfx=suf=sum=best=INT_MIN;
	}
	void merge(node a,node b)
	{
		pfx = max(a.pfx,a.sum+b.pfx);
		suf = max(b.suf,a.suf+b.sum);
		sum = a.sum+b.sum;
	   best = max(max(a.best,b.best),a.suf+b.pfx);
	}
};
node tree[4*N+1];
void buildtree(ll a[],ll index,ll s,ll e)
{
	if(s>e) return;
	if(s==e) {
		tree[index].pfx=a[s];
		tree[index].suf=a[s];
		tree[index].sum=a[s];
		tree[index].best=a[s];
		return;
	}
	ll mid=(s+e)/2;
	buildtree(a,2*index,s,mid);
	buildtree(a,2*index+1,mid+1,e);
	node left = tree[2*index];
	node right = tree[2*index+1];
	tree[index].merge(left,right);
	return;
}
node query(ll index,ll s,ll e,ll l,ll r)
{
	if(s>r || e<l)
	return tree[0];
	
	if(s>=l && e<=r) 
	return tree[index];
	
	ll mid=(s+e)/2;
	node left = query(2*index,s,mid,l,r);
	node right = query(2*index+1,mid+1,e,l,r);
	node result;
	result.merge(left,right);
	return result;
}
int main() {
	// your code goes here
	dude;
	int n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	buildtree(a,1,0,n-1);
	ll m;
	cin>>m;
	while(m--)
	{
		ll l,r;
		cin>>l>>r;
		node result = query(1,0,n-1,l-1,r-1);
		cout<<result.best<<"\n";
	}
	return 0;
}
