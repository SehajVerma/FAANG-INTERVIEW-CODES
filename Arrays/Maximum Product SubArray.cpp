https://www.youtube.com/watch?v=vtJvbRlHqTA

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int curr_max=a[0];
    int curr_min=a[0];
    int prev_max=a[0];
    int prev_min=a[0];

    int ans=a[0];
    for(int i=1;i<n;i++)
    {
        curr_max = max(max(prev_max*a[i],prev_min*a[i]),a[i]);
        curr_min = min(min(prev_max*a[i],prev_min*a[i]),a[i]);
        ans = max(ans,curr_max);
        prev_max = curr_max;
        prev_min = curr_min;
    }
    cout<<curr_max;
}
