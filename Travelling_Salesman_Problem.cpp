vaise iski bruteforce complexity O(n!) 
kyuki sare solutions permutations hai ek he string ke
 A-------B
 -       -
 -     - - 
 -   -   -
 - -     -
 C-------D
 solutions can be A-B-C-D-A
                  B-C-D-A-D
                  C-D-A-D-B
                  D-A-B-C-D
 so n! times one element can be rotated
 
 But with this bitMask approach complexity is O(2^N * N)
let there be 4 cities
0000
0001
---
---
---
1111

 These are till 2^N-1  //2^4-1 i.e 1 to 15 
 so for one city we have to search for other N-1 cities so complexity O(2^N * N)

Also this problem refers to the shortest weighted HAMILTONIAN path in a graph
Hamiltonian path refers to the path in which all vertice are visited once .

#include <bits/stdc++.h>
using namespace std;
#define n 4
int dp[16][n]; //dp[2^n][n]
  
//dp array to store D-A se, D-B se, D-C se phele se he compute krke rakh lenge

int dist[n][n];
int tsp(int mask,int pos)
{
    if(mask==((1<<n)-1))
    return dist[pos][0];

    if(dp[mask][pos]!=-1)
    return dp[mask][pos];
    int ans = INT_MAX;
    for(int city=0;city<n;city++)
    {
        if((mask & 1<<city)==0)
        {
         int newAns = dist[pos][city] + tsp((mask | 1<<city ),city);
         ans = min(ans,newAns);
        }
    }
    return dp[mask][pos]=ans;
}
int main() {
    memset(dp,-1,sizeof(dp));
    
    memset(dist,0,sizeof(dist));
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
           cin>>dist[i][j];
    }
    cout<<tsp(1,0);
}
