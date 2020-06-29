#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
      float v;
      float w;
};
node input[100];
bool comp(node g1,node g2)
{
    return (g1.v/g1.w) > (g2.v/g2.w) ;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  float W;
	  cin>>n>>W;
	  for(int i=0;i<n;i++)
	  {
	     cin>>input[i].v>>input[i].w; 
	  }
	  sort(input,input+n,comp);
	  float cost=0;
	  for(int i=0;i<n;i++)
	  {
	      cost += W >= input[i].w?input[i].v : (float)(W/input[i].w)*input[i].v;
	      W-=input[i].w;
	      if(W<=0)
	      break;
	  }
	  cout<<fixed << setprecision(2)<<cost<<endl;
	}
	return 0;
}
