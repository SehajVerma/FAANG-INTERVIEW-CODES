#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  int left=0;
  int right=n-1;
  int area=INT_MIN;
  while(left<right)
  {
    area=max(area,min(a[left],a[right])*(right-left));
    if(a[left]<a[right])
    left++;
    else
    right--;
  }
  cout<<area;
  return 0;
}
