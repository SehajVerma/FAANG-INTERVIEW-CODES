#include <bits/stdc++.h>
using namespace std;
int max_dist=0;
class graph
{
    map<int,list<pair<int,int>>>adj;
public:
   void addedge(int u,int v,int weight)
   {
       adj[u-1].push_back({v-1,weight});
       adj[v-1].push_back({u-1,weight});
   }
   void dfs(int src,int n)
   {
       map<int,int>visited;
       map<int,int>countt;
       for(auto it:adj)
       visited[it.first]=countt[it.first]=0;
       dfsHelper(src,visited,countt,n);
   }
   int dfsHelper(int node,map<int,int> &visited,map<int,int> &countt,int n)
   {
       visited[node]=1;
       countt[node]=1;
       for(auto child : adj[node])
       {
           int src = child.first;

           if(!visited[src])
           {
            countt[node] += dfsHelper(src,visited,countt,n);
            max_dist += min(countt[src],n-countt[src])*2*child.second;
           }
       }
       return countt[node];
   }
};
int main()
{
    graph g;
    g.addedge(1,2,3);
    g.addedge(2,3,4);
    g.addedge(2,4,1);
    g.addedge(4,5,8);
    g.addedge(5,6,5);
    //g.addedge(1,2,3);
    //g.addedge(2,3,2);
    //g.addedge(3,4,2);
    g.dfs(0,6);
    cout<<max_dist;
}
