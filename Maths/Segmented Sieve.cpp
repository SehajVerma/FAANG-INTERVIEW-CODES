This is used when [L,R] is in range >10^8 but R-L<=10^8.
Complexity is O(Nlog(logN))
Just a slight modification in Simple Sieve method
Explanation - https://www.youtube.com/watch?v=fByR5N-TseY
              https://www.youtube.com/watch?v=khPI7I8H8CM&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=30

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> prime_sieve(int *p,int r)
{
    for(int i=3;i*i<=r;i=i+2)
    p[i] = 1;

    for(int i=3; i*i<=r; i=i+2)
    {
        for(int j = i*i; j <= r; j=j+i)
        p[j] = 0;
    }
    p[1]=0;
    p[0]=0;
    p[2]=1;
    
    vector<int>prime;
    for(int i=0;i<=r;i++)
    {
        if(p[i]==1)
        prime.push_back(i);
    }
    return prime;
}
vector<int> prime_segmented_sieve(vector<int>&v,int l,int r)
{
    int segprime[r-l+1];
    for(int i=0;i<r-l+1;i++) segprime[i]=1;
    
    for(int i=0;i<v.size();i++)
    {
        int base = (l/(v[i]))*v[i];
        if(base < l)
        base+=v[i];
        for(int j = base; j <= r; j = j+v[i])
        {
            segprime[j-l]=0;
        }
        if(base==l)
        segprime[base-l]=1;
    }

    vector<int>s_prime;

    for(int i=0;i<=r-l;i++)
    {
        if(segprime[i]==1)
        s_prime.push_back(i+l);
    }
    return s_prime;
}
int main() {
    int p[1000000]={0};
    int l,r;
    cin>>l>>r;
    vector<int>v = prime_sieve(p,r);
 
    vector<int>w = prime_segmented_sieve(v,l,r);
    for(int i=0;i<w.size();i++)
    cout<<w[i]<<" ";
}
