#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int element1=a[0],element2=0,count1=1,count2=0;
    for(int i=1;i<n;i++)
    {
        if(element1==a[i])
        count1++;
        else if(element2==a[i])
                 count2++;
            else if(count1==0){
                   element1=a[i];
                   count1++;
                   }
                else if(count2==0){
                    element2=a[i];
                    count2++;
                }
                else
                {
                    count1--;
                    count2--;
                }
    }
    int ncount1=0;
    int ncount2=0;
    for(int i=0;i<n;i++)
    {
        if(element1==a[i])
        ncount1++;
        if(element2==a[i])
        ncount2++;
    }
    vector<int>ans;
    if(ncount1>n/3)
     ans.push_back(element1);
    if(ncount2>n/3)
     ans.push_back(element2);

    if(ans.size()==0)
    cout<<"No Majority Elements";
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}
