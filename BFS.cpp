#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj(6,vector<int>());
class graph
{
  public:
  void addedge(int u,int v)
  {
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
  void bfs(int src)
  {
      queue<int>q;
      int visited[6]={0};
      q.push(src);
      visited[src]=1;
      while(!q.empty())
      {
          int topp=q.front();
          q.pop();
          cout<<topp<<" ";
         for(int i:adj[topp])
         {
             if(!visited[i])
             {
                 visited[i]=1;
                 q.push(i);
             }
         } 
      }
  }
};
int main() {
    graph g;
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(2,1);
    g.addedge(2,4);
    g.addedge(2,3);
    g.addedge(3,5);
    g.addedge(4,3);
    g.bfs(0);
}
