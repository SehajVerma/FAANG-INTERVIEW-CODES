https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   int n;
	   cin>>n;
	   int a;
	   priority_queue<int,vector<int>,greater<int>>pq;
	   for(int i=0;i<n;i++){
	       cin>>a;
	       pq.push(a);
	   }
	   unsigned long long int cost=0;
	   while(pq.size() > 1)
	   {
	       int x = pq.top(); pq.pop();
	       int y = pq.top(); pq.pop();
	       cost = cost + x+y;
	       pq.push(x+y);
	   }
	   cout<<cost<<endl;
	}
	return 0;
}
