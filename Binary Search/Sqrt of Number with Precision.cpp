#include <iostream>
using namespace std;
double sq(double A,int p) {
    if(A==0)
    return 0;
    long long int low=1;
    long long int high=A/2;
    double ans=1;
    while(low<=high)
    {
        long long int mid = (low+high)/2;
        if(mid<=A/mid)
        {
            ans=mid;
            low=mid+1;
        }
        else
        high=mid-1;
    }
    double inc=0.1;
    for(int i=0;i<p;i++)
    {
        while(ans*ans<=A){
        ans+=inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}
int main() {
    double n;
    int p;
    cin>>n>>p;
    cout<<sq(n,p);


}
