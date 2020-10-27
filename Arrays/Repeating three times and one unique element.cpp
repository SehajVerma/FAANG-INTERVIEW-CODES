#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int tn = INT_MAX,tn1=0,tn2=0;
    
    for(int i=0;i<n;i++)
    {
        int cntn = tn & a[i];
        int cntn1 = tn1 & a[i];
        int cntn2 = tn2 & a[i];
        
        tn = tn & (~cntn);
        tn1 = tn1 | cntn;
        
        tn1 = tn1 & (~cntn1);
        tn2 = tn2 | cntn1;
        
        tn2 = tn2 & (~cntn2);
        tn = tn | cntn2;
    }
    cout<<tn1;
}
