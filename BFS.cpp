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
/*

// BFS WITH SHORTEST PATH

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
  void bfs(int src,int dest)
  {
      queue<int>q;
      int visited[6]={0};
      int dist[6]={0};
      int parent[6]={-1};
      q.push(src);

      dist[src]=0;

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

                 dist[i]=dist[topp]+1;
                 parent[i]=topp;
             }
         }

      }
      cout<<endl;
      int temp=dest;
      while(temp!=-1)
      {
          cout<<temp<<" ";
          temp = parent[temp];
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
    g.bfs(0,5);
}
*/
