#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj(4,vector<int>());
int timer=0;
class graph
{
  public:
  void addedge(int u,int v)
  {
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
  void dfs(int node,int parent)
  {
      int visited[4]={0};
      int inn[6]={0};
      int low[6]={0};
      dfsHelper(node,parent,visited,inn,low);
  }
  void dfsHelper(int node,int parent,int visited[],int inn[],int low[])
  {
      visited[node]=1;
      inn[node]=low[node]=timer;
      timer++;
      for(auto child : adj[node])
      {
          if(child == parent) continue;
          if(visited[child])
          {
              //back-edge
              low[node] = min(low[node],inn[child]);
          }
          else
          {
              dfsHelper(child,node,visited,inn,low);
              if(low[child]>inn[node])
              cout<<node<<" "<<child<<" is a bridge"<<"\n";
              //Now for this node if there is a path to its previous ancestor 
              low[node] = min(low[node],low[child]);
          }

      }
  }
};
int main() {
    graph g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.dfs(0,-1);
}
