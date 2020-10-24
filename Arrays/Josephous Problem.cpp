#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>v,int k,int i)
{
    if(v.size()==1)
    return v[0];

    int index = (i+k)%v.size();
    v.erase(v.begin()+index);
    return solve(v,k,index);
}
int main() {
    int n,k;
    cin>>n>>k;

    vector<int>v;
    for(int i=0;i<n;i++)
    v.push_back(i+1);
    cout<<solve(v,k-1,0);
}
